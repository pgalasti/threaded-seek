#ifndef T_SEEK_ENGINE_H
#define T_SEEK_ENGINE_H

#include "ds/ConcurrentQueue.h"
#include "TSeekFile.h"


#include <list>
#include <string>

namespace TSeek {


  // Making this abstract so I can wire in other ways
  // to search in the future
  class Engine {
  public:  
    using ResultList = std::list<std::string>;

    virtual ~Engine() = default;
    virtual ResultList search() = 0; 
  };

  class EngineV1 : public Engine {
  public:
    EngineV1(const std::string& rootPath, const File::SearchParams& params);
    virtual ResultList search() override;

  private:
    DS::ConcurrentQueue<File> m_fileSearchQueue;
    File m_rootFile;    
  };

}

#endif // Guard
