#ifndef T_SEEK_CONCURRENT_QUEUE
#define T_SEEK_CONCURRENT_QUEUE

#include <queue>
#include <mutex>
#include <cstddef>

namespace TSeek::DS {
  template <typename T>
  class ConcurrentQueue {
  public:
    ConcurrentQueue()                                   = default;
    ~ConcurrentQueue()                                  = default;
    
    // Keep it simple and just remove these
    ConcurrentQueue(const ConcurrentQueue&)             = delete;
    ConcurrentQueue(ConcurrentQueue&&)                  = delete;
    ConcurrentQueue& operator=(const ConcurrentQueue&)  = delete;
    ConcurrentQueue& operator=(ConcurrentQueue&&)       = delete;

    std::size_t size() const { return m_queue.size(); }
    bool empty() const       { return size() == 0uz; }

    const T front() const;
    const T back() const;

    void push(const T& t);
    void push(T&& t);

    template<class... Args>
    void emplace(Args&&... args);

    void pop();
  private:
    mutable std::mutex m_mtx;
    std::queue<T> m_queue;
  };
}

#include "ConcurrentQueue.tpp"

#endif
