// Task 1.1: Flashing an existing application.
// Task 1.2: Using library functions instead of hard-coded register access
// Task 1.3: Adding a blinking LED
// Task 1.4: GPIO Input Polling
// Task 1.5: Simple UART output

#include <ESLab3driverLib/driverlib.h>     
#include <msp.h>                           
#include <stdint.h>                       
#include <stdio.h>                         

#include "lab3.h"                          

// Global variable defining the number of cycles of the busy loop
uint32_t g_waitcycles = WAIT_CYCLES * WAIT_INIT_MULTI;

void main(void) {
  task_1_1();
}
