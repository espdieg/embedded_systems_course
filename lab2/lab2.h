// Base scaffold for the Lab1 in Embedded Systems (ES). The goal of this
// Lab is that the students get to know the platform MSP432P401R LaunchPad
// Development Kit.

#ifndef LAB2_H_
#define LAB2_H_

#include <msp.h>                           
#include <stdint.h>                        
#include <stdio.h>                  

// function to toggle the LED pins
inline void toggle(uint8_t LEDpins) {
  P1OUT ^= (LEDpins & 0x01);        // toggles P1.0 if bit 0 is set. ^= means XOR
  P2OUT ^= (LEDpins & 0x0e) >> 1;   
}

// function to print a formatted string using UART
inline void uart_println(const char* str, ...) {
  static char print_buffer[256];
  va_list lst;
  va_start(lst, str);
  vsnprintf(print_buffer, 256, str, lst);
  str = print_buffer;
  
  while (*str) {
    while (!(UCA0IFG & EUSCI_A_IFG_TXIFG));
    UCA0TXBUF = *str;
    str++;
  }
  while (!(UCA0IFG & EUSCI_A_IFG_TXIFG));
  UCA0TXBUF = '\r';
  while (!(UCA0IFG & EUSCI_A_IFG_TXIFG));
  UCA0TXBUF = '\n';
}

// Task 2: GPIO Input Polling
void task_2(void);

// Task 3: Simple UART output
void task_3(void);

// Task 4: Simple UART input from PC
void task_4(void);

// Task 5: Simple UART input from PC
void task_5(void);

#endif /* LAB2_H_ */

