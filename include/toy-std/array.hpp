#pragma once

#include <toy-std/cstddef.hpp>
#include <toy-std/exception.hpp>

namespace toy {
template <typename T, size_t S> class array {
public:
  using value_type = T;
  using size_type = ::size_t;
  using difference_type = ::ptrdiff_t;
  using reference = value_type &;
  using const_reference = const reference;
  using pointer = value_type *;
  using const_pointer = const value_type *;

  reference at(size_type pos) {
    if (!this->_check_bounds(pos))
      throw toy::out_of_range("Out of range");
    return this->_data[pos];
  }
  const_reference at(size_type pos) const {
    if (!this->_check_bounds(pos))
      throw toy::out_of_range("Out of range");
    return this->_data[pos];
  }

  reference operator[](size_type pos) { return _data[pos]; }

  const_reference operator[](size_type pos) const { return _data[pos]; }

  reference front() { return _data[0]; }
  const_reference front() const { return _data[0]; }

  reference back() { return _data[S - 1]; }
  const_reference back() const { return _data[S - 1]; }

  T *data() noexcept { return _data; }
  const T *data() const { return _data; }

  constexpr size_t size() const { return S; }

private:
  T _data[S];
  bool _check_bounds(size_type pos) { return pos >= 0 && pos < S; }
};
} // namespace toy