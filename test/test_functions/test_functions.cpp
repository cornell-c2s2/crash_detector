#include <cstring>
#include <unity.h>

void test_functions() {
    TEST_ASSERT_EQUAL(0, 0);
    TEST_ASSERT_EQUAL(123, 123);
}

#ifdef DESKTOP
int main(int argc, char *argv[]) {
    UNITY_BEGIN();
    RUN_TEST(test_functions);
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
