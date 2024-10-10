#include "lab2.h"                                 

#define LED_RED         (0x01)
#define RGB_RED         (0x02)
#define RGB_GREEN       (0x04)
#define RGB_BLUE        (0x08)

uint32_t print_and_increment(uint32_t value);     // Function prototype declaration

void task_4(void) {
  // Declaring a delay counter
  volatile uint32_t i;

  // Declaring a toggling counter
  uint32_t counter = 0;

  // Toggling the LED 25 times, with an increasing toggling delay
  while (counter < 25) {
    // Toggle  LED
    toggle(LED_RED);
    
    // function call
    counter = print_and_increment(counter);

    static uint32_t delay = 0;  // Declare the initial toggling delay
    delay = delay + 3000;       // Increase delay by ~10ms
    for (i = 0; i < delay; i++);
  }

  // Your task consist in reaching this print statement.
  uart_println("Congrat's! You completed task 4 :-) ");

  while (1) {
    /* An empty loop preventing the program from exiting */
  }
}

// function that prints counter value and then increments it
uint32_t print_and_increment(uint32_t value) {
    uart_println("Counter = %u", value);  // print current counter value
    value += 1;                           // increment counter
    return value;                         // return counter value
}
