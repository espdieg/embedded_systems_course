#ifndef LAB3_H_
#define LAB3_H_

#define UART_INTERFACE  EUSCI_A0_BASE

#define WAIT_INIT_MULTI ((uint32_t)(15))                 // Multiplier for longer busy wait
#define WAITCYCLES_BASE ((uint32_t)(10000))              // Base value for the wait cycles calculation
#define WAIT_CYCLES     ((uint32_t)(WAITCYCLES_BASE))    // Constant define for the initial number of waiting cycles

extern uint32_t g_waitcycles;                            // Declaration of the global variable defining the number of cycles of the busy loop

// void task_1_1(void);
// void task_1_2(void);
// void task_1_3(void);
// void task_2_2(void);
// void task_2_3(void);
void task_3(void);

#ifdef __DRIVERLIB__H_

static const eUSCI_UART_Config uart_config =
{
  -1, // Clock Source Selection
  -1, // Baudrate Divider BRDIV
  -1, // Clock Compensation Factor UCxBRF
  -1, // Clock Compensation Factor UCxBRS
  -1, // Parity Bits
  -1, // Endianness
  -1, // Stop Bits
  -1, // Interface Mode
  -1  // Low Frequency/Oversampling Baud Mode
};

static const char str_s1[] = "S0 is pressed.";
static const char str_s2[] = "S1 is pressed.";

// brief Inline function to configure the UART as needed in this lab session 
inline void lab3_configureUART(
     const eUSCI_UART_Config *config
   )
{
 // Selecting P1.2 and P1.3 in UART mode
GPIO_setAsPeripheralModuleFunctionOutputPin
            (
              GPIO_PORT_P1,
              GPIO_PIN2 | GPIO_PIN3,
              GPIO_PRIMARY_MODULE_FUNCTION
            );
 // Configuring UART Module
 UART_initModule(UART_INTERFACE, config);
 // Enable UART module
 UART_enableModule(UART_INTERFACE);
}

// brief Send string via UART peripheral param str Pointer to the message to send param ... printf-style parameters
inline void uart_println(const char* str, ...) {
  static char print_buffer[256];
  va_list lst;
  va_start(lst, str);
  vsnprintf(print_buffer, 256, str, lst);
  str = print_buffer;
  while (*str) {
    while (!(EUSCI_A_CMSIS(UART_INTERFACE)->IFG & EUSCI_A_IFG_TXIFG));
    EUSCI_A_CMSIS(UART_INTERFACE)->TXBUF = *str;
    str++;
  }
  while (!(EUSCI_A_CMSIS(UART_INTERFACE)->IFG & EUSCI_A_IFG_TXIFG));
  EUSCI_A_CMSIS(UART_INTERFACE)->TXBUF = '\r';
  while (!(EUSCI_A_CMSIS(UART_INTERFACE)->IFG & EUSCI_A_IFG_TXIFG));
  EUSCI_A_CMSIS(UART_INTERFACE)->TXBUF = '\n';
}

#endif /* __DRIVERLIB__H_ */
#endif /* LAB3_H_ */
