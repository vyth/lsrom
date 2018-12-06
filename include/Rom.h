/**
*   @file   Rom.h 
*   @brief  Class containing each Rom's information and executability.
*   @author Duke Hauge
*   @date   11/14/2018
**/

#ifndef ROM_H_
#define ROM_H_

#include <string>

#include "Debug.h"
namespace RomViewer {

class Rom {
  public:
    ///defaul constructor
    Rom();
    ///constructor
    Rom(const std::string &fullPath, const std::string &localPath);
    ///destructor
    ~Rom();

    
    /**
    *   @brief Returns rom's full path
    *   @return std::string 
    **/
    std::string GetFullPath(); 

    /**
    *   @brief Returns rom's local path
    *   @return std::string 
    **/
    std::string GetLocalPath(); 

    /**
    *   @brief Returns rom object information
    *   @return std::string
    **/
    std::string ToString();
  protected:
  private:
    std::string fullPath; ///< path to rom
    std::string localPath; ///< path from root rom folder
};

}//namespace RomViewer

#endif 
