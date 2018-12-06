#include <boost/program_options.hpp>
#include <boost/format.hpp>
#include <iostream>

#include "../include/OutputFormatter.h"
#include "../include/Genre.h"

namespace RomViewer {

/* Init Functions */
OutputFormatter::OutputFormatter() { }
OutputFormatter::~OutputFormatter() { }

/* Primary Functions */
void OutputFormatter::PrintFullGenre(Genre * g) {
  PrintGenre(g);

  for(auto sg : g->GetSubGenres())
    PrintGenre(sg.second);
}

void OutputFormatter::PrintGenre(Genre * g) {
  std::string out = "[" + g->GetName() + "]\n";
    for(auto r : g->GetLeafRoms())   
      out += "\t\t> " + r.second->GetLocalPath() + "\n";

  std::cout << out;
}

/********************************** Settings **********************************/

void OutputFormatter::PrintHelp(
                            boost::program_options::options_description &desc) {
  std::cout << desc << std::endl;
}

void OutputFormatter::PrintVersion() {
  std::cout << "lsrom v. " 
            << VERSION_MAJOR << "." << VERSION_MINOR
            << std::endl;
}

}//namespace RomViewer

