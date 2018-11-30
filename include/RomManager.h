
/**
*   @file   RomManager 
*   @brief  Manages the folder tree of the rom for display.
*   @author Duke Hauge
*   @date   11/15/2018
**/

#ifndef ROM_MANAGER_H_
#define ROM_MANAGER_H_

#include <string>

namespace RomViewer {

class RomManager {
  public:
    ///constructor
    RomManager();
    ///destructor
    ~RomManager();

    
    /**
    *   @brief T
    *   @param P        T
    *   @return O 
    **/
    std::string ToString();
  protected:
  private:
    int id; ///< id
};

}//namespace RomViewer

#endif 
