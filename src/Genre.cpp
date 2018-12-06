#include "../include/Genre.h"
#include "../include/Rom.h"

#include "../include/Debug.h"

namespace RomViewer {

/* Init Functions */

Genre::Genre(bool first) { fae = first; }
  
Genre::Genre(const std::string &fullPath, const std::string &localPath) {
  this->fullPath = fullPath;
  this->name     = localPath;
}

Genre::~Genre() {
  if(fae) 
    for(auto g : fae_genres) delete g.second;
	
	for(auto r : roms)
		delete r.second;
}

/* Primary Functions */

void Genre::AddSubGenre(Genre *sg) {
	subGenres[sg->GetFullPath()] = sg;

}
void Genre::AddRom(Rom *rom) {
  roms[rom->GetFullPath()] = rom;
}

/* Set Functions */

/* Get Functions */

std::unordered_map<std::string,Rom*>   Genre::GetLeafRoms()  {return roms;}
std::unordered_map<std::string,Genre*> Genre::GetSubGenres() {return subGenres;}

std::string Genre::GetFullPath() {return fullPath;}
std::string Genre::GetName()     {return name;}

/* First-Among-Equals Functions */

void Genre::AddGenreFAE(const std::string &key, const std::string &romDir) {
  std::string localPath = key.substr(romDir.size());

  //add new genre to map
  fae_genres[key] = new Genre(key,localPath);

  //loop through subgenres
  size_t next_index = localPath.find_last_of("/"); 
  std::string parentGenre = localPath;
  while(next_index > 0 ){ 
    parentGenre = parentGenre.substr(0,next_index);
    
    fae_genres[romDir + parentGenre]->AddSubGenre(fae_genres[key]);

    //next parent
    next_index = parentGenre.find_last_of("/"); 
  }
}

void Genre::AddRomFAE(const std::string &fullPath, const std::string &romDir) {
	std::string localPath = fullPath.substr(romDir.size());
	std::string genre = fullPath.substr(0, fullPath.find_last_of("/"));

	
	fae_genres[genre]->AddRom(new Rom(fullPath, localPath)); 
}

Genre *Genre::FindGenreFAE(const std::string &name) {
  //TODO only finds first
	Debug::Print("Searching for: [" + name + "]");

	for(auto g : fae_genres) {
		std::string localPath = g.second->GetName();
	}

	return NULL;
}

std::unordered_map<std::string, Genre*> & Genre::GetFAEGenres() {
	return fae_genres;
}

Genre * Genre::operator[](std::string key) {	
	if(fae) return fae_genres[key];

	return NULL;
}

}//namespace RomViewer

