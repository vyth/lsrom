#include "../include/RomManager.h"
#include "../include/Rom.h"
#include "../include/Genre.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <iostream>

namespace RomViewer {

/* Init Functions */

RomManager::RomManager() {
  recentExecutes.resize(10);

  fae_genre = new Genre();
}

RomManager::~RomManager() {
  //save state to config file
  boost::property_tree::ptree pt;
  
  pt.put("romdir", romDir);
  for(int i=0; i < 10; i++)
    pt.put("recents." + std::to_string(i+1), recentExecutes[i]);

  boost::property_tree::write_ini(configPath, pt);

  delete fae_genre;
}

void RomManager::Init() {
  LoadRomFileSystem();
}

void RomManager::LoadRomFileSystem() {
  namespace fs = boost::filesystem;

  Debug::Print("romDir = " + romDir);

  fs::recursive_directory_iterator it(romDir), end;

  while(it != end) {
    std::string fullPath = it->path().string();

    if(fs::is_directory(it->path())) { //directory
      fae_genre->AddGenreFAE(fullPath, romDir);
    }
    else { //file
			fae_genre->AddRomFAE(fullPath, romDir);
    }

    boost::system::error_code ec;
    it.increment(ec);
  }
}

/* Primary Functions */
void RomManager::PushToRecents(const std::string & cmd) {
  //TODO: parse the cmd to readable format
  recentExecutes.insert(recentExecutes.begin(), cmd);
}

/* Set Functions */
void RomManager::SetRecentEntry(int i, const std::string & cmd) {
    recentExecutes[i] = cmd;
}

void RomManager::SetRomDirectory(const std::string &dir) { 
  if(boost::filesystem::exists(dir)) romDir = dir; 
  else {
    Debug::Print("Error: Rom directory does not exist.\n\t\t> " + dir);
    //TODO exit(-1);
  }
}

void RomManager::SetConfigPath(const std::string &path) { 
  if(boost::filesystem::exists(path)) configPath = path;
  else {
    Debug::Print("Error: Configuration file does not exist.\n\t\t> " + path);
    exit(-1);
  }
}
/* Get Functions */

Genre *RomManager::GetFAEGenre() { return fae_genre; }

std::string RomManager::ToString() {
  std::string out = "Config: " + configPath + "\n";
  out += "Rom Directory: " + romDir + "\nRecents:\n";
  for(int i=0; i < 10; i++) 
    out += std::to_string(i+1) + ". " + recentExecutes[i] + "\n";  

  return out;
}

} //namespace RomViewer
