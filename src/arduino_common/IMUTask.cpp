#include <IMUTask.hpp>
#include <Arduino.h>
#include <StateFieldRegistry.hpp>

IMUTask::IMUTask(SFR &sfr) : ControlTask(sfr)
{
  Adafruit_BNO055 bno = Adafruit_BNO055(55);
};

void IMUTask::setup()
{
  // this code runs once
  Serial.println("IMU Task Setup");
  Serial.println("Orientation Sensor Test");
  Serial.println("");
  /* Initialise the sensor */
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    // while(1);
  }
  delay(1000);

  bno.setExtCrystalUse(true);
};

void IMUTask::execute()
{
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

// display position and velocity at x, y, z axis
void IMUTask::display()
{
  sensors_event_t event;
  bno.getEvent(&event);

  // time in milliseconds -> \delta t = 0.001 s
  unsigned int prev_time = millis();

  // assume initial position and velocity are 0
  // not a valid assumption, need to change later
  float vel_init_x = 0, vel_init_y = 0, vel_init_z = 0;
  float pos_init_x = 0, pos_init_y = 0, pos_init_z = 0;

  // stay in while loop until user termination
  while (1)
  {
    unsigned int curr_time = millis();
    unsigned int dt = curr_time - prev_time;

    // prevent divide by 0 error
    if (dt == 0) {
      delay(1);
      continue;
    }

    // get current position and velocity
    float curr_x = event.orientation.x;
    float curr_y = event.orientation.y;
    float curr_z = event.orientation.z;

    float vel_dx = curr_x * dt;
    float vel_dy = curr_y * dt;
    float vel_dz = curr_z * dt;

    vel_init_x += vel_dx;
    vel_init_y += vel_dy;
    vel_init_z += vel_dz;

    float pos_dx = vel_init_x * dt;
    float pos_dy = vel_init_y * dt;
    float pos_dz = vel_init_z * dt;

    pos_init_x += pos_dx;
    pos_init_y += pos_dy;
    pos_init_z += pos_dz;

    /* Display the floating point data */
    Serial.print("Time: ");
    unsigned int time = millis();
    Serial.print(time);
    Serial.println("");

    Serial.print("Acceleration\tX: ");
    Serial.print(event.orientation.x, 4);
    Serial.print("\tY: ");
    Serial.print(event.orientation.y, 4);
    Serial.print("\tZ: ");
    Serial.print(event.orientation.z, 4);
    Serial.println("");

    Serial.print("Velocity\tX: ");
    Serial.print(vel_init_x, 4);
    Serial.print("\tY: ");
    Serial.print(vel_init_y, 4);
    Serial.print("\tZ: ");
    Serial.print(vel_init_z, 4);
    Serial.println("");

    Serial.print("Position\tX: ");
    Serial.print(pos_init_x, 4);
    Serial.print("\tY: ");
    Serial.print(pos_init_y, 4);
    Serial.print("\tZ: ");
    Serial.print(pos_init_z, 4);
    Serial.println("\n");

    // update every 0.1 seconds
    delay(100);
  }
}
\\
bool IMUTask::detectCrash(float init_a, float curr_a, float dt) {
  // arbitrary threshold for change in acceleration when dt = 0.001 s
  float crash_threshold = 0.5;

  // adjust crash threshold based on dt
  float adjusted_crash_threshold = crash_threshold * dt;

  return abs(curr_a - init_a) > adjusted_crash_threshold;
}