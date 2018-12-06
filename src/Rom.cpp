#include "../include/Rom.h"

namespace RomViewer {

/* Init Functions */

Rom::Rom() {} 
Rom::Rom(const std::string &fullPath, const std::string &localPath) {
  this->fullPath = fullPath;
  this->localPath = localPath;
}

Rom::~Rom() {

}

/* Primary Functions */

/* Set Functions */

/* Get Functions */
std::string Rom::GetFullPath()  { return fullPath; }
std::string Rom::GetLocalPath() { return localPath; }

std::string Rom::ToString() {
  return "Full\t= " + GetFullPath() + 
         "\nLocal\t= " + GetLocalPath() + "\n";
}

} //namespace RomViewer
