#include "../include/main.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <string>
#include <unordered_map>


#include "../include/constants/constants.h"
#include "../include/RomManager.h"
#include "../include/OutputFormatter.h"
#include "../include/Genre.h"
#include "../include/Debug.h"

int main(int argc, char **argv) {
  namespace po = boost::program_options;
	namespace rv = RomViewer;

  //parse input
  po::options_description desc("Options");
  po::variables_map       vm;
  rv::InitProgramOptions(argc, argv, vm, desc);

  auto getOptionKey = [](std::string option) {
    return option.substr(0,option.find(","));
  };
  auto isOptionSet  = [&vm,getOptionKey](std::string option) {
    return vm.count(getOptionKey(option));
  };

  rv::RomManager rm;
  rv::LoadConfiguration(vm, rm);
  rm.Init();

	rv::Genre *fae = rm.GetFAEGenre();
	std::unordered_map<std::string, rv::Genre*> fae_genres = fae->GetFAEGenres();

  //Show Help 
  if(isOptionSet(kOptionHelp))    rv::OutputFormatter::PrintHelp(desc);
  //Show Version
  if(isOptionSet(kOptionVersion)) rv::OutputFormatter::PrintVersion();

  //Show All
  if(isOptionSet(kOptionShowAll)) { 
    rv::Debug::Print("Option not yet implemented.\n"); 
  }
  //Show Recent
  if(isOptionSet(kOptionRecent))  {
    rv::Debug::Print("Option not yet implemented.\n"); 
  }
  //Show Shuffled
  if(isOptionSet(kOptionShuffle)) {
    rv::Debug::Print("Option not yet implemented.\n"); 
  }
  //Genre Searching 
  if(isOptionSet(kOptionGenre)) {
		std::string genre = vm[getOptionKey(kOptionGenre)].as<std::string>();

		for(auto g : fae_genres) {
			std::string path = g.second->GetFullPath();
			if(path.find(genre) != std::string::npos) {
				rv::OutputFormatter::PrintGenre(g.second);
			}
		}
  }
  //Show Listing by Console
  if(isOptionSet(kOptionConsole)) {
    rv::Debug::Print("Option not yet implemented.\n"); 
  }
  //Search for Rom
  if(isOptionSet(kOptionSearch))  {
    rv::Debug::Print("Option not yet implemented.\n"); 
  }
  //Launch Rom from Emulator 
  if(isOptionSet(kOptionExecute)) {
    std::string exec_cmd = vm[getOptionKey(kOptionExecute)].as<std::string>(); 

    //case 1: integer, execute rom with ID 
    //case 2: fuzzy name search with list
    rm.PushToRecents(exec_cmd);
  }
  //Add Emulator
  if(isOptionSet(kOptionAddEmu))  { 
    rv::Debug::Print("Option not yet implemented.\n"); 
  }
  
  return 1;
}

namespace RomViewer {

void InitProgramOptions(int argc, char **argv,
                      boost::program_options::variables_map & vm,
                      boost::program_options::options_description & desc) {
  namespace po = boost::program_options;

  //initialize the desc reference
  desc.add_options()
  (kOptionShowAll,  "List all roms by console.")
  (kOptionRecent,   "List recently executed roms.")
  (kOptionNewest,   "List 10 newest roms.")
  (kOptionShuffle,  "List 10 random roms.")

  (kOptionGenre,     po::value<std::string>(),
   "List all roms by genre.")
  (kOptionConsole,   po::value<std::string>(), 
   "List all roms for inputed consoles.")
  (kOptionSearch,    po::value<std::string>(), 
   "Search for roms similar to input.")
  (kOptionExecute,   po::value<std::string>(),
   "Launch a rom from list of known emulators.")

  (kOptionHelp,       "Show help command.")
  (kOptionVersion,    "Show current version.")
  (kOptionConfigFile, "Use custom config file.")
  (kOptionSetRomDir,  po::value<std::string>(),
   "Set root directory for roms.")
  (kOptionAddEmu,     po::value<std::string>(), 
   "Add emulator for console.");

  //initialize the vm reference
  try{ po::store(po::parse_command_line(argc, argv, desc),vm); } 
  catch(const std::exception & e) { }
}

void LoadConfiguration(boost::program_options::variables_map & vm,
                       RomManager & rm) {
  auto getOptionKey = [](std::string option) {
    return option.substr(0,option.find(","));
  };
  auto isOptionSet  = [&vm,getOptionKey](std::string option) {
    return vm.count(getOptionKey(option));
  };

  //Set/Change Config File Path
  std::string confPath = (isOptionSet(kOptionConfigFile)) ? 
                         vm[getOptionKey(kOptionConfigFile)].as<std::string>() 
                         : kDefaultConfigPath;
  rm.SetConfigPath(confPath);

  //load config file
  boost::property_tree::ptree pt;
  boost::property_tree::ini_parser::read_ini(confPath, pt);

  //read in recent executes
  for(int i=0; i < 10; i++)
    rm.SetRecentEntry(i,pt.get<std::string>("recents." + std::to_string(i+1)));


  //Set/Change Rom Directory
  if(isOptionSet(kOptionSetRomDir)) 
    rm.SetRomDirectory(vm[getOptionKey(kOptionSetRomDir)].as<std::string>());
  else
    rm.SetRomDirectory(pt.get<std::string>("romdir"));
}

} //namespace RomViewer
