#include "lab2.h"                             

// bitmask constants for each LED color
#define LED_RED         (0x01)
#define RGB_RED         (0x02)
#define RGB_GREEN       (0x04)
#define RGB_BLUE        (0x08)

void task_2(void) {
  // Declaring a delay counter
  volatile uint16_t i;

  // Declaring a toggling counter to count LED toggles
  uint32_t counter = 0;

  while (1) {
    // Toggling the red LED
    toggle(LED_RED);

    // Printing the counter via UART and incrementing the counter
    uart_println("Current counter value is: %u", counter);
    counter += 1;

    // Delay of ~166ms
    for (i = 0; i < 50000; i++);
  }
}
