#include <msp.h>                              
#include <stdint.h>                           
#include <stdio.h>                            
#include "ESLab3driverLib/driverlib.h"  // lab asks us to include this for this task
#include "lab3.h"   

// Removed the define statements which were listed here since we won't use them in this task

void task_1_2(void) { 
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;       // Stopping the Watchdog Timer
  uint32_t count = 0;                               // Simple counter variable

  // Removed the 3 lines of code provided in task 1_1 and wrote the single 
  // line below which performs the equivalent
  GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0); // setAsOutputPin function grabbed from gpio.c and
                                                // the values are grabbed from gpio.h
  while(1) {
    GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0);  // Toggle Output State of P1.0. From gpio.c file
    // ---------------------------------------------------------------------------------- //
    //                                    Placeholder 1                                   //
    // ---------------------------------------------------------------------------------- //
    for(count = 0; count < g_waitcycles; count++)   // Busy Loop for Delay
    {
      // ---------------------------------------------------------------------------------//
      //                                  Placeholder 2                                   //
      // ---------------------------------------------------------------------------------//
    }
  }
}
