#ifndef T_SEEK_ENGINE_H
#define T_SEEK_ENGINE_H

#include <list>
#include <string>

namespace TSeek {

  // Making this abstract so I can wire in other ways
  // to search in the future
  class Engine {
  public:  
    virtual ~Engine() = default;
    virtual std::list<std::string> search() = 0; 
  };

  class EngineV1 : public Engine {
    virtual std::list<std::string> search() override;  
  };

}

#endif // Guard
