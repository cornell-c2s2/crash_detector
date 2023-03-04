#include <cstring>
#include <unity.h>
#include <RingBuffer.h>
#include <iostream>

void test_simple() {

  auto ring_buff = RingBufferSmall();
  char popped;

  ring_buff.insert('A');
  TEST_ASSERT_EQUAL(ring_buff.get_size(), 1);
  TEST_ASSERT_EQUAL(ring_buff.get_capacity(), 8);

  popped = ring_buff.pop();
  TEST_ASSERT_EQUAL(popped, 'A');

  ring_buff.insert('A');
  ring_buff.insert('B');
  ring_buff.insert('C');

  TEST_ASSERT_EQUAL(ring_buff.get_size(), 3);
  TEST_ASSERT_EQUAL(ring_buff.get_capacity(), 8);

  popped = ring_buff.pop();
  TEST_ASSERT_EQUAL(popped, 'A');

  popped = ring_buff.pop();
  TEST_ASSERT_EQUAL(popped, 'B'); 

  popped = ring_buff.pop();
  TEST_ASSERT_EQUAL(popped, 'C');

    // TEST_ASSERT_EQUAL_STRING("foofoo", double_string("foo").c_str());
    // TEST_ASSERT_EQUAL_STRING("foofoo", double_string("foo").c_str());
    // TEST_ASSERT_EQUAL_STRING("foofoo", double_string("foo").c_str());
    // TEST_ASSERT_EQUAL_STRING("foofoo", double_string("foo").c_str());
    // TEST_ASSERT_EQUAL_STRING("foofoo", double_string("foo").c_str());
    // TEST_ASSERT_EQUAL(1,1);
    // std::cout << "test" << std::endl;

}

void test_longer() {
  auto ring_buff = RingBufferSmall();
  char popped;

  for(size_t i = 0; i < 256; i++) {
    char expected = (char)i;
    ring_buff.insert(expected);
    popped = ring_buff.pop();

    TEST_ASSERT_EQUAL(popped, expected);
  }
}

void test_full_and_empty_buffer() {
  auto ring_buff = RingBufferSmall();
  char popped;
  for(size_t i = 0; i < ring_buff.get_capacity(); i++) {
    ring_buff.insert('F');
  }

  // assert that rejects insertion on full
  TEST_ASSERT_EQUAL(ring_buff.insert('G'), -1);

  for(size_t i = 0; i < ring_buff.get_capacity(); i++) {
    // check that all pops work
    TEST_ASSERT_EQUAL(ring_buff.safe_pop(&popped), 0);
    TEST_ASSERT_EQUAL(popped, 'F');
  }

  // check that you can't pop from empty buffer
  TEST_ASSERT_EQUAL(ring_buff.safe_pop(&popped), -1);

}

#ifdef DESKTOP
int main(int argc, char *argv[]) {
    UNITY_BEGIN();

    RUN_TEST(test_simple);
    RUN_TEST(test_longer);
    RUN_TEST(test_full_and_empty_buffer);

    return UNITY_END();
}
#else
#include <Arduino.h>
void setup() {
    delay(10000);
    Serial.begin(9600);
    test_functions();
}

void loop() {}
#endif
