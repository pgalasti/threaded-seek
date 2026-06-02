#include <utility>

namespace TSeek::DS {

  template <typename T>
  const T Queue<T>::front() const {
    std::lock_guard lock(m_mtx);
    return m_queue.front();
  }

  template <typename T>
  const T Queue<T>::back() const {
    std::lock_guard lock(m_mtx);
    return m_queue.back();
  }

  template <typename T>
  void Queue<T>::push(const T& t) {
    std::lock_guard lock(m_mtx);
    m_queue.push(t);
  }

  template <typename T>
  void Queue<T>::push(T&& t) {
    std::lock_guard lock(m_mtx);
    m_queue.push(std::move(t));
  }

  template <typename T>
  template <class... Args>
  void Queue<T>::emplace(Args&&... args) {
    std::lock_guard lock(m_mtx);
    m_queue.emplace(std::forward<Args>(args)...);
  }

  template <typename T>
  void Queue<T>::pop() {
    std::lock_guard lock(m_mtx);
    m_queue.pop();
  }

}
