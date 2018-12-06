
/**
*   @file   RomManager 
*   @brief  Manages the folder tree of the rom for display.
*   @author Duke Hauge
*   @date   11/15/2018
**/

#ifndef ROM_MANAGER_H_
#define ROM_MANAGER_H_

#include <string>
#include <vector>
#include <unordered_map>

#include "Debug.h"

namespace RomViewer {

class Genre;

class RomManager {
  public:
    /**
    *   @brief Constructor
    *   @return this
    **/
    RomManager();
    ///destructor
    ~RomManager();

    /**
    *   @brief Initialize rom manager
    *   @return void
    **/
    void Init();

    /**
    *   @brief Loads list of roms into a vector
    *   @return void
    **/
    void LoadRomFileSystem();

    /**
    *   @brief Pushes current execute to top of recent list 
    *   @param dir    
    *   @return void
    **/
    void PushToRecents(const std::string &cmd);

    /**
    *   @brief Sets i-th entry of recent executes to command.
    *   @param i recentExecute index to change
    *   @param cmd new command
    *   @return void
    **/
    void SetRecentEntry(int i, const std::string &cmd);

    /**
    *   @brief Sets the root rom directory
    *   @param dir    new root directory
    *   @return void
    **/
    void SetRomDirectory(const std::string & dir);

    /**
    *   @brief Sets the config file path
    *   @param path 
    *   @return void
    **/
    void SetConfigPath(const std::string & path);
    
    /**
    *   @brief returns the first-among-equals genre
    *   @return Genre * 
    **/
    Genre *  GetFAEGenre();
    /**
    *   @brief Convert RomManager infomation to string
    *   @return string
    **/
    std::string ToString();
  protected:
  private:
    std::string configPath; ///< path to configuration file
    std::string romDir; ///< rom collection's root directory

    ///ten most recent roms launched
    std::vector<std::string> recentExecutes; 
    ///first-among-equal genre object
    Genre *fae_genre;
};

}//namespace RomViewer

#endif 
