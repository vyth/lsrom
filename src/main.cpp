#include <iostream>
#include <string>


#include "../include/main.h"
#include "../include/constants/constants.h"

int main(int argc, char **argv) {
  namespace po = boost::program_options;

  //parse input
  po::options_description desc("Options");
  po::variables_map       vm;
  RomViewer::InitProgramOptions(argc, argv, vm, desc);

  auto getOptionKey = [&vm](std::string option) {
    return option.substr(0,option.find(","));
  };
  auto isOptionSet  = [&vm,getOptionKey](std::string option) {
    return vm.count(getOptionKey(option));
  };


  //execute user input
  if(isOptionSet(kOptionShowAll)) {
    std::cout << "[Show All is set.]\n";
  }
  else if(isOptionSet(kOptionGenre)) {
    std::cout << "[Genre is set.]\n";
    std::string exec_cmd = vm[getOptionKey(kOptionExecute)].as<std::string>(); 
    std::cout << "Execute romid #" << exec_cmd << std::endl;

  }
  else if(isOptionSet(kOptionConsole)) {
    std::cout << "[Console is set.]\n";
    std::string exec_cmd = vm[getOptionKey(kOptionExecute)].as<std::string>(); 
    std::cout << "Execute romid #" << exec_cmd << std::endl;

  }
  else if(isOptionSet(kOptionRecent)) {
    std::cout << "[Recent is set.]\n";
    std::string exec_cmd = vm[getOptionKey(kOptionExecute)].as<std::string>(); 
    std::cout << "Execute romid #" << exec_cmd << std::endl;

  }
  else if(isOptionSet(kOptionSearch)) {
    std::cout << "[Search is set.]\n";
    std::string exec_cmd = vm[getOptionKey(kOptionExecute)].as<std::string>(); 
    std::cout << "Execute romid #" << exec_cmd << std::endl;

  }
  else if(isOptionSet(kOptionExecute)) {
    std::cout << "[Execute is set.]\n";
    std::string exec_cmd = vm[getOptionKey(kOptionExecute)].as<std::string>(); 
    std::cout << "Execute romid #" << exec_cmd << std::endl;
  }
  else if(isOptionSet(kOptionSetRomDir)) {
    std::cout << "[Set Rom Directory  is set.]\n";
    std::string exec_cmd = vm[getOptionKey(kOptionExecute)].as<std::string>(); 
    std::cout << "Execute romid #" << exec_cmd << std::endl;

  }
  else if(isOptionSet(kOptionAddEmu)) {
    std::cout << "[Add Emulator is set.]\n";
    std::string exec_cmd = vm[getOptionKey(kOptionExecute)].as<std::string>(); 
    std::cout << "Execute romid #" << exec_cmd << std::endl;

  }
  else if(isOptionSet(kOptionHelp)) {
    std::cout << "[Help is set.]\n";

    std::cout << desc << std::endl;
  }
  else if(isOptionSet(kOptionVersion)) {
    std::cout << "[Version is set.]\n";
    
  }

  return 1;
}

namespace RomViewer {

void InitProgramOptions(int argc, char **argv,
                      boost::program_options::variables_map & vm,
                      boost::program_options::options_description & desc) {
  namespace po = boost::program_options;

  //numbering in oder of below list
  std::string s_opt1, s_opt2, s_opt4, s_opt6, s_opt7;
  int i_opt3, i_opt5;

  //initialize the desc reference
  desc.add_options()
  (kOptionHelp,     "Show help command.")
  (kOptionVersion,  "Show current version.")

  (kOptionShowAll,  "List all roms by console.")
  (kOptionGenre,     po::value<std::string>(&s_opt1), 
   "List all roms by genre.")
  (kOptionConsole,   po::value<std::string>(&s_opt2), 
   "List all roms for inputed consoles.")
  (kOptionRecent,    po::value<int>(&i_opt3),
  "List recently executed roms.")

  (kOptionSearch,    po::value<std::string>(&s_opt4), 
   "Search for roms similar to input.")
  (kOptionExecute,   po::value<int>(&i_opt5),
   "Launch a rom from list of known emulators.")

  (kOptionSetRomDir,  po::value<std::string>(&s_opt6),
   "Set root directory for roms.")
  (kOptionAddEmu,     po::value<std::string>(&s_opt7), 
   "Add emulator for console.");

  //initialize the vm reference
  try{ po::store(po::parse_command_line(argc, argv, desc),vm); } 
  catch(const std::exception & e) { }
}

} //namespace RomViewer
