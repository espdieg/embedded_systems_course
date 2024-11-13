#include <msp.h>                              
#include <stdint.h>                         
#include <stdio.h>                           
#include "ESLab3driverLib/driverlib.h"  
#include "lab3.h"   

void task_1_3(void) {
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;       // Stopping the Watchdog Timer
  uint32_t count = 0;                               // Simple counter variable

  // Removed the 3 lines of code provided in task 1_1. Below is the equivalent
  GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0); // LED1 per schematic
  GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0); // RGBLED_RED per schematic

  // The lab instructs us to have "RGB LED blink alternating to LED1"
  // So we need to set one to start as low and the other as high
  GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0); // LED1 set to start low
  GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0); // RGBLED_RED starts high
  while(1) {
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);  // Toggle Output State of P1.0. From gpio.c file
    GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN0);  // toggle RGBLED_RED
    // ---------------------------------------------------------------------------------- //
    //                                    Placeholder 1                                   //
    // ---------------------------------------------------------------------------------- //
    for(count = 0; count < g_waitcycles; count++) {  // Busy Loop for Delay
      // ---------------------------------------------------------------------------------//
      //                                  Placeholder 2                                   //
      // ---------------------------------------------------------------------------------//
    }
  }
}
