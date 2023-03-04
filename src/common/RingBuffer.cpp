#include <RingBuffer.h>

template <class T, size_t N>
RingBuffer<T,N>::RingBuffer() : backing_array() {
}

template <class T, size_t N>
size_t RingBuffer<T,N>::get_size() {
  return size;
}

template <class T, size_t N>
size_t RingBuffer<T,N>::get_capacity() {
  return capacity;
}

template <class T, size_t N>
int RingBuffer<T,N>::insert(T elem) {
  if( size >= backing_array.size() ) {
    return -1;
  }

  // back_pointer;
  backing_array[back_pointer] = elem;
  size++;
  back_pointer = (back_pointer + 1) % N;

  return 0;
}

template <class T, size_t N>
T RingBuffer<T,N>::pop() {
  if( size <= 0) {
    throw "Cannot pop from empty ring buffer";
  }

  size--;
  T temp = backing_array[front_pointer];

  front_pointer = (front_pointer + 1) % N;

  return temp;
}

template <class T, size_t N>
int RingBuffer<T,N>::safe_pop(T* elem_ptr) {
  if( size <= 0) {
    return -1;
  }

  *elem_ptr = backing_array[front_pointer];
  front_pointer = (front_pointer + 1) % N;
  size--;

  return 0;
}