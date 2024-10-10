#include "lab2.h"                               

// bitmask constants for each LED color
#define LED_RED         (0x01)
#define RGB_RED         (0x02)
#define RGB_GREEN       (0x04)
#define RGB_BLUE        (0x08)

void task_3(void) {
  // Declare a delay counter
  volatile uint32_t i;  //changed this from 16 bit to 32 bit

  // Declaring a toggling counter to count LED toggles
  uint32_t counter = 0;

  // Toggle the LED 25 times, with an increasing toggling delay
  while (counter < 25) {
    // Toggle LED
    toggle(LED_RED);

    // Print counter value and increment it
    uart_println("counter = %u",counter);
    counter += 1;
    
    uint32_t delay = 0;  // Declare the initial toggling delay
    delay = delay + 3000;       // Increase delay by ~10ms
    for (i = 0; i < delay; i++);
  }

  // Your task consist in reaching this print statement.
  uart_println("Congrat's! You completed task 3 :-) ");

  while (1) {
    // An empty loop preventing the program from exiting
  }
}
