#pragma once

#include <array>

template <class T, size_t N>
class RingBuffer {
  size_t front_pointer = 0;
  size_t back_pointer  = 0;
  size_t size          = 0;
  size_t capacity      = N;
  std::array<T, N> backing_array;

public:
  RingBuffer();
  size_t get_size();
  size_t get_capacity();
  int insert(T elem);
  T pop();
  int safe_pop(T* elem_ptr);
};

template class RingBuffer<char, 1024>;
using RingBufferDefault = RingBuffer<char, 1024>;

template class RingBuffer<char, 8>;
using RingBufferSmall = RingBuffer<char, 8>;