#include "../include/Rom.h"

namespace RomViewer {

/* Init Functions */

Rom::Rom() {

}

Rom::~Rom() {

}

/* Primary Functions */

/* Set Functions */

/* Get Functions */

std::string Rom::ToString() {
  return std::string("ID: ") + std::to_string(this->id); 
}

}
