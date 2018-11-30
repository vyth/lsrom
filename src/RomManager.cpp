#include "../include/RomManager.h"

namespace RomViewer {

/* Init Functions */

RomManager::RomManager() {

}

RomManager::~RomManager() {

}

/* Primary Functions */

/* Set Functions */

/* Get Functions */

std::string RomManager::ToString() {
  return std::string("ID: ") + std::to_string(this->id); 
}

} //namespace RomViewer
