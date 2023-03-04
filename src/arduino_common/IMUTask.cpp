#include <IMUTask.hpp>
#include <Arduino.h>
#include <StateFieldRegistry.hpp>

IMUTask::IMUTask(SFR& sfr) : ControlTask(sfr) {
  Adafruit_BNO055 bno = Adafruit_BNO055(55);
};

void IMUTask::setup() {
  // this code runs once
  Serial.println("IMU Task Setup");
  Serial.println("Orientation Sensor Test"); Serial.println("");
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    // while(1);
  }
  delay(1000);
    
  bno.setExtCrystalUse(true);
};

void IMUTask::execute() {
  // this code runs repeatedly
  Serial.println("IMU Task Execute");

  /* Get a new sensor event */ 
  sensors_event_t event; 
  bno.getEvent(&event);
  /* Display the floating point data */
  Serial.print("Time: ");
  unsigned int time = millis();
  Serial.print(time);
  Serial.print("\tX: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tY: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.println("");
  
  delay(100);
};