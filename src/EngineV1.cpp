#include "TSeekEngine.h"

using namespace TSeek;

EngineV1::EngineV1(const std::string& rootDirectory, const File::SearchParams& params) 
	: m_rootFile{rootDirectory, params, true}
{

}

Engine::ResultList EngineV1::search() {

  std::list<std::string> results;

  // .. 
  
  return results;
}
