/* 
 *  @file globals.hpp
 *  @brief Header file for global enums, typedefs, constants, variables
 *  and declarations.
 *  @author
*/

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include "./kOptions.h"


/*********************************** Consts **********************************/

const char *kDefaultConfigPath = "lsrom.conf";//"~/.config/lsrom.conf";
const char *kDefaultRomDir     = "/home/quagmire/shared/roms/";//"~/roms"

/*********************************** Enums ***********************************/

/// Enum for different consoles emulated
enum Consoles { 
  ps1, 
  ps2, 
  nes, 
  snes 
};

#endif
