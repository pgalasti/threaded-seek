#include "TSeekFile.h"
#include "TSeekEngine.h"

#include <iostream>
#include <memory>
#include <list>
#include <cassert>

int main(int argc, char** argv) {

  TSeek::File testFile(".", TSeek::File::SearchParams{"Testing", true});

  std::unique_ptr<TSeek::Engine> pEngine = std::make_unique<TSeek::EngineV1>();
  std::list<std::string> results = pEngine->search();

  assert(results.empty() && "Should be empty. Not implemented yet.");

  return 0;
}
