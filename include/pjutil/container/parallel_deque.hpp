
#pragma once

#include <deque>
#include <mutex>

namespace pjutil {
template <typename T> class ParallelDeque {
  using Mutex = std::mutex;
  using Container = std::deque<T>;

public:
  void push_front(const T &val) {
    std::lock_guard<Mutex> lk(_mtx);
    _data.push_front(val);
  }

  void push_back(const T &val) {
    std::lock_guard<Mutex> lk(_mtx);
    _data.push_back(val);
  }

  size_t size() const {
    std::lock_guard<Mutex> lk(_mtx);
    return _data.size();
  }

  T pop_back() {
    std::lock_guard<Mutex> lk(_mtx);
    T back = std::move(_data.back());
    _data.pop_back();
    return back;
  }

  T pop_front() {
    std::lock_guard<Mutex> lk(_mtx);
    T front = std::move(_data.front());
    _data.pop_front();
    return front;
  }

private:
  Container _data;
  mutable Mutex _mtx;
};
} // namespace pjutil