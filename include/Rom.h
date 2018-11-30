/**
*   @file   Rom.h 
*   @brief  Class containing each Rom's information and executability.
*   @author Duke Hauge
*   @date   11/14/2018
**/

#ifndef ROM_H_
#define ROM_H_

#include <string>

namespace RomViewer {

class Rom {
  public:
    ///constructor
    Rom();
    ///destructor
    ~Rom();

    
    /**
    *   @brief Returns the class instance's id
    *   @return std::string containing instance id
    **/
    std::string ToString();
  protected:
  private:
    int id; ///< id
};

}//namespace RomViewer

#endif 
