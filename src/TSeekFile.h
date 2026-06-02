#ifndef T_SEEK_FILE_H
#define T_SEEK_FILE_H


#include <string_view>
#include <string>
#include <exception>
#include <optional>
#include <list>

namespace TSeek {


  class File {
  
  public:
    
    struct SearchParams {
      std::string text {};
      bool ignoreCase  {};
    };

    explicit File(std::string_view path, const SearchParams& searchParams, bool delaySearch = false);
    ~File() = default;

    bool isFound() const;
    friend class EngineV1;

  private:
    using DirectoryList = std::list<std::string>;

    DirectoryList search(); 
    
    enum SearchState {

      Initialized,
      InProgress,
      Complete,
      Error,
      NumOfSearchStates // Meta data of state
    };

    SearchState searchState              {Initialized};
    SearchParams searchParams            {};
    std::string path                     {};
    std::optional<std::string> lineFound {};
    bool isDirectory                     {false}; // May define as an enum type later

    class FileSearchException : public std::exception {
      public:

        FileSearchException(std::string_view message) : message{message} {}
        const char* what() const noexcept {
          return message.c_str(); 
        }

      private:
        std::string message;
    };

  };

} // TSeek Namespace

#endif
