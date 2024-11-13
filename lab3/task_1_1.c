#include <msp.h>                              
#include <stdint.h>                         
#include <stdio.h>                          
#include "lab3.h"                         

// These register base address and register address offsets can be found in the MSP432P4xx
// Reference Manual Chapter 10.
#define REGBASEADR  ((uint32_t)(0x40004C00))  // Base addr. of Port 1 configuration register
#define REGOFS_SEL0 ((uint32_t)(0x0000000A))  // Addr. Offset for Select0-Register in Port 1
#define REGOFS_SEL1 ((uint32_t)(0x0000000C))  // Select1 offset in Port 1  conf. reg.
#define REGOFS_DIR  ((uint32_t)(0x00000004))  // Direction offset in Port 1 conf. reg.
#define REGOFS_OUTV ((uint32_t)(0x00000002))  // Output Value offset in Port 1 conf. reg.

void task_1_1(void) {
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;       // Stopping the Watchdog Timer
  uint32_t count = 0;                               // Simple counter variable

  // Configure P1.0 by setting the mode to simple I/O (Select 0 & 1 = 0b00) and direction to
  // output. The configuration information can be found in the MSP432P4xx Reference Manual
  // Chapter 10.
  HWREG16(REGBASEADR + REGOFS_SEL0) &= ~(0x0001);   // Set bit 0 of Select 0 register to 0
  HWREG16(REGBASEADR + REGOFS_SEL1) &= ~(0x0001);   // Set bit 0 of Select 1 register to 0
  HWREG16(REGBASEADR + REGOFS_DIR)  |=  (0x0001);   // Set bit 0 of Direction register to 1

  while(1) {
    HWREG16(REGBASEADR + REGOFS_OUTV) ^= (0x0001);  // Toggle Output State of P1.0
    // ---------------------------------------------------------------------------------- //
    //                                    Placeholder 1                                   //
    // ---------------------------------------------------------------------------------- //
    for(count = 0; count < g_waitcycles; count++) {   // Busy Loop for Delay
      // ---------------------------------------------------------------------------------//
      //                                  Placeholder 2                                   //
      // ---------------------------------------------------------------------------------//
    }
  }
}
