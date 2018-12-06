#include "../include/Debug.h"

#include <iostream>

namespace RomViewer {

void Debug::Print(const std::string &msg, const uint priority) {
	if(DEBUG_ON >= priority) {
		std::cerr << msg << std::endl;
	}
}

}//namespace RomViewer


