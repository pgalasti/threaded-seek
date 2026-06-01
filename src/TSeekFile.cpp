#include "TSeekFile.h"

using namespace TSeek;

File::File(std::string_view path, const SearchParams& params, bool delayedSearch/*=false*/) : searchParams{params}, path{path} {
  if(!delayedSearch) {
    search();
  }
}

void File::search() {

  if(searchState == InProgress) {
    throw FileSearchException("Search is in progress");
  } else if(searchState != Initialized) {
    throw FileSearchException("Search has already been conducted");
  }

  searchState = InProgress;

  // File IO here
  // Do we need to a conditional variable to notify thread manager?

  searchState = Complete;
  //lineFound to be set if line is found.
}

bool File::isFound() const {
  return lineFound.has_value();
}
