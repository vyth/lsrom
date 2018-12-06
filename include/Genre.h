
/**
*   @file   Genre.h 
*   @brief  Class storing genre information.
*   @author Duke Hauge
*   @date   12/01/2018
**/

#ifndef GENRE_H_
#define GENRE_H_

#include <string>
#include <unordered_map>

#include "Debug.h"
#include "Rom.h"

namespace RomViewer {

class Genre {
  public:
    ///default constructor
    Genre(bool first=false);
    ///constructor
    
    /**
    *   @brief Constructor for regular genre object
    *   @param fullPath path to directory of genre's origin
    *   @param localPath path from root rom directory
    *   @return Genre object
    **/
    Genre(const std::string &fullPath, 
          const std::string &localPath);
    ///destructor
    ~Genre();

    /**
    *   @brief Add subgenre to this genre
    *   @param sg subgenre associated with this genre
    *   @return void
    **/
    void AddSubGenre(Genre *sg);
    

    /**
    *   @brief Add rom to genre, ignore dupes.
    *   @param rom        rom to be added
    *   @return void
    **/
    void AddRom(Rom *rom);
    
    /**
    *   @brief Returns this genre's direct rom matches
    *   @return map of roms ordered by their fullPath
    **/
    std::unordered_map<std::string, Rom*> GetLeafRoms();

    /**
    *   @brief Returns this genre's subgrens
    *   @return map of subgenres ordered by their fullPath
    **/
    std::unordered_map<std::string, Genre*> GetSubGenres();

    /**
    *   @brief Returns this genre's fullpath
    *   @return std::string fullPath
    **/
    std::string GetFullPath();

    /**
    *   @brief Returns this genre's local path
    *   @return std::string name
    **/
    std::string GetName();

    // First-Among-Equal Functions
    /**
    *   @brief Adds genre to unordered_map
    *   @param fullPath  fullPath to genre directory
    *   @param romDir    root rom directory
    *   @return void
    **/
    void AddGenreFAE(const std::string &fullPath, 
                     const std::string &romDir);

    /**
    *   @brief Adds rom to proper genre
    *   @param fullPath  fullPath to rom file
    *   @param romDir    root rom directory
    *   @return void
    **/
    void AddRomFAE(const std::string &fullPath, 
                   const std::string &romDir);


    /**
    *   @brief Returns most likely genre.
    *   @param name   genre being searched for
    *   @return Genre* pointer to the nearest genre
    **/
    Genre *FindGenreFAE(const std::string &name);

    /**
    *   @brief Returns FAE's genres 
    *   @return fae_genres   reference to unordered map
    **/ 
    std::unordered_map<std::string, Genre*> & GetFAEGenres();

    /**
    *   @brief Returns FAE's genre at entry key
    *   @param key     fullPath to genre
    *   @return Genre* pointer to the nearest genre
    **/
    Genre * operator[](std::string key);

  protected:
  private:
    bool fae; ///< true if first-among-equals
    std::string fullPath; ///< path to all roms in this genre
    std::string name; ///< genre name to display


    std::unordered_map<std::string, Genre*> subGenres; 
    std::unordered_map<std::string, Rom*> roms; 

    //First-Among-Equal
    std::unordered_map<std::string, Genre*> fae_genres; 
};

}//namespace RomViewer

#endif 
