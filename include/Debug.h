
/**
*   @file   Debug 
*   @brief  T
*   @author Duke Hauge
*   @date   0
**/

#ifndef DEBUG_H_
#define DEBUG_H_

#define DEBUG_ON 1

#include <string>

namespace RomViewer {

class Debug {
  public:
    /**
    *   @brief Prints to stderr, filters based on priority
    *   @param priority low(1), med(2) or high(3) integer
    *   @param msg      message printed to stderr
    *   @return void
    **/
    static void Print(const std::string &msg,const uint priority=1);

  protected:
  private:
};

}//namespace RomViewer

#endif 
