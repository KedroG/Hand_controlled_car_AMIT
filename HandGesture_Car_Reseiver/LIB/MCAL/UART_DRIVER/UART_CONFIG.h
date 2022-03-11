
#ifndef UART_DRIVER_UART_CONFIG_H_
#define UART_DRIVER_UART_CONFIG_H_
/*modes of UART:
 * asynchronous
 * synchronous
 */
#define UART_mode_select asynchronous
/*
 * parity_disabled    0b00
   reserved           0b01
   parity_enable_even 0b10
   parity_enable_odd  0b11
 */

#define parity_select parity_disabled
#define select_stop_bit two
#define Fosc 8000000
#define baud 9600
#endif /* UART_DRIVER_UART_CONFIG_H_ */
