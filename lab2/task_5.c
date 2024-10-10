#include "lab2.h"                               

#define LED_RED         (0x01)
#define RGB_RED         (0x02)
#define RGB_GREEN       (0x04)
#define RGB_BLUE        (0x08)

void task_5(void) {
  // Declaring a delay counter
  volatile uint32_t i;

  // Declaring a toggling counter
  uint32_t counter = 0;

  // variable that contains the active LED assignment 
  uint8_t activeLED = 0;

  // infinite loop that toggles LED colors and they flash on and off 
  while(1) {
    if (counter %3 == 0) {
        activeLED = LED_RED | RGB_RED ;
    } else if (counter %3 == 1) {
        activeLED = LED_RED | RGB_GREEN ;
    } else if (counter %3 == 2) {
        activeLED = LED_RED | RGB_BLUE ;
    }

    // the line below produces the same result as the while loop above
    //activeLED = LED_RED | (1 << (counter %3 + 1));

    // Toggle LED ON
    toggle(activeLED);

    // Delay of ~333ms
    for (i = 0; i < 100000; i++);

    // Toggle LED OFF
    toggle(activeLED);

    // Delay of ~333ms
    for (i = 0; i < 100000; i++);

    // Printing counter value and then increment it
    uart_println("counter = %u",counter);
    counter += 1;
  }
}
