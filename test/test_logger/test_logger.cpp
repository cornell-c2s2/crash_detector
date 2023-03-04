#include <cstring>
#include <unity.h>
#include <Logger.h>
#include <iostream>

void test_logger() {

    TEST_ASSERT_EQUAL_STRING("foofoo", double_string("foo").c_str());
    TEST_ASSERT_EQUAL_STRING("foofoo", double_string("foo").c_str());
    TEST_ASSERT_EQUAL_STRING("foofoo", double_string("foo").c_str());
    TEST_ASSERT_EQUAL_STRING("foofoo", double_string("foo").c_str());
    TEST_ASSERT_EQUAL_STRING("foofoo", double_string("foo").c_str());
    TEST_ASSERT_EQUAL(1,1);
    std::cout << "test" << std::endl;

}

#ifdef DESKTOP
int main(int argc, char *argv[]) {
    UNITY_BEGIN();
    RUN_TEST(test_logger);
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
