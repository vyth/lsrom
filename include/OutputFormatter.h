
/**
*   @file   OutputFormatter 
*   @brief  Formats the information into strings that are readable in the
*           console enviroment.
*   @author Duke Hauge
*   @date   12/03/2018
**/

#ifndef OUTPUT_FORMATTER_H_
#define OUTPUT_FORMATTER_H_

#define VERSION_MAJOR 1
#define VERSION_MINOR 0

#include <string>

namespace RomViewer {

class Genre;

class OutputFormatter {
  public:
    ///constructor
    OutputFormatter();
    ///destructor
    ~OutputFormatter();

    static void PrintFullGenre(Genre *g); 
    static void PrintGenre(Genre *g); 

    static void PrintHelp(boost::program_options::options_description & desc);
    static void PrintVersion();
  protected:
  private:
};

}//namespace RomViewer

#endif 
