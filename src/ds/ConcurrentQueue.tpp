#include <utility>

namespace TSeek::DS {

  template <typename T>
  const T ConcurrentQueue<T>::front() const {
    std::lock_guard lock(m_mtx);
    return m_queue.front();
  }

  template <typename T>
  const T ConcurrentQueue<T>::back() const {
    std::lock_guard lock(m_mtx);
    return m_queue.back();
  }

  template <typename T>
  void ConcurrentQueue<T>::push(const T& t) {
    std::lock_guard lock(m_mtx);
    m_queue.push(t);
  }

  template <typename T>
  void ConcurrentQueue<T>::push(T&& t) {
    std::lock_guard lock(m_mtx);
    m_queue.push(std::move(t));
  }

  template <typename T>
  template <class... Args>
  void ConcurrentQueue<T>::emplace(Args&&... args) {
    std::lock_guard lock(m_mtx);
    m_queue.emplace(std::forward<Args>(args)...);
  }

  template <typename T>
  void ConcurrentQueue<T>::pop() {
    std::lock_guard lock(m_mtx);
    m_queue.pop();
  }

}
