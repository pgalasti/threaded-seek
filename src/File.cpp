#include "TSeekFile.h"

File::File(std::string_view path, const SearchParams& params, bool delayedSearch/*=false*/) {

}

void File::search() {
  if(searchState != Initialized) {
    throw FileSearchException("Search has already been conducted");
  }

  searchState = InProgress;

  // File IO here
  // Do we need to a conditional variable to notify thread manager?

}

bool File::isFound() const {

  return true;
}
