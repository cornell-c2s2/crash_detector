#include <Arduino.h>

void execute()
{
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
    Serial.write("LED cycle\n");
}

void setup()
{
    // put your setup code here, to run once:
    delay(2000);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    // put your main code here, to run repeatedly:
    int pin = 3;
    if (digitalRead(pin) == HIGH) {
        // current time?
        Serial.write("");
    }
    
     execute();
}