
/**
*   @file   main.h 
*   @brief  Main file for executable
*   @author Duke Hauge
*   @date   11/14/2018
**/

#ifndef MAIN_H_
#define MAIN_H_

#include <boost/program_options.hpp>

namespace RomViewer {
  
/**
*   @brief Gets user's options from the command line.
*   @param argc     Number of arguments.
*   @param argv     Array of arguments passed through the command line.
*   @param vm       Variable map for command line input initiated here.
*   @param desc     Options descriptions is initiated here.
*   @return void
*
*   @author Duke Hauge
**/
void InitProgramOptions(const int argc, char **arga, 
                        boost::program_options::variables_map & vm,
                        boost::program_options::options_description & desc);


}//namespace RomViewer

#endif 
