/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */
#include <stdio.h>      //include Serial Library
#include <time.h>       //include Time library (might not need)?
#include <metal/gpio.h> //include GPIO library, <https://sifive.github.io/freedom-metal-docs/apiref/gpio.html>
//#define builtin_LED 5 //IC's GPIO = 5, pin silkscreen = 13, this line won't work, we need an integer...
//custom write delay function since we do not have one like an Arduino
// #include <string>

void delay(int number_of_microseconds) //not actually number of seconds
{
  // Converting time into multiples of a hundred nS
  int hundred_ns = 10 * number_of_microseconds;
  
  // Storing start time
  clock_t start_time = clock();
  
  // looping till required time is not achieved
  while (clock() < start_time + hundred_ns);
  
}//end delay
int main (void) {
  // std::string foo;
  //make instance of GPIO
  struct metal_gpio *led0;
  //Note: The sequence of these commands matter!
  //Get gpio device handle, i.e.) define IC pin here where IC's GPIO = 5, pin silkscreen = 13
  //this is the GPIO device index that is referenced from 0, make sure to check the schematic
  led0 = metal_gpio_get_device(0);
  // quick check to see if we set the metal_gpio up correctly, this was based on the "sifive-welcome.c" example code
  if (led0 == NULL) {
    printf("LED is null.\\n");
    return 1;
  }
  //Pins are set when initialized so we must disable it when we use it as an input/output
  metal_gpio_disable_input(led0, 19);
  //Set as gpio as output
  metal_gpio_enable_output(led0, 19);
  //Pins have more than one function, make sure we disconnect anything connected...
  metal_gpio_disable_pinmux(led0, 19);
  //Turn ON pin
  metal_gpio_set_pin(led0, 19, 1);
  while (1) {//loop through, sort of like an Arduino loop()
    //Turn OFF pin
    printf("Turning LED off\\n");
    metal_gpio_set_pin(led0, 19, 0);
    //Use custom "delay" function
    delay(10000); //2000000 "micro-seconds" ~ 1 second, through experimentation... 
    //Turn ON pin
    printf("Turning LED on\\n");
    metal_gpio_set_pin(led0, 19, 1);
    //Use custom "delay" function
    delay(10000);
    /***************************************************
    //crude method of "delaying" without messing with the cpu's interrupts...
    for (int i = 0; i < 25000; i++) {
      metal_gpio_set_pin(led0, 5, 0);
    }
    for (int i = 0; i < 25000; i++) {
      metal_gpio_set_pin(led0, 5, 1);
    }
    ***************************************************/
  }
  // return
  return 0;
}//end main