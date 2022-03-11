/*
 * UART_PRIVATE.h
 *
 *  Created on: Oct 29, 2021
 *      Author: Omar Abdalbaset
 */

#ifndef UART_DRIVER_UART_PRIVATE_H_
#define UART_DRIVER_UART_PRIVATE_H_

#define UDR      *((volatile u8 *)(0x2C))
#define UCSRA    *((volatile u8 *)(0x2B))
#define RXC       7
#define TXC       6
#define UDRE      5
#define FE        4
#define DOR       3
#define PE        2

#define UCSRB    *((volatile u8 *)(0x2A))
#define RXCIE     7
#define TXCIE     6
#define UDRIE     5
#define RXEN      4 //enable receiver
#define TXEN      3 //enable transmitter
#define UCSZ2     2

#define UCSRC    *((volatile u8 *)(0x40))
#define URSEL     7
#define UMSEL     6
#define UPM1      5
#define UPM0      4
#define USBS      3
#define UCSZ1     2
#define UCSZ0     1
#define UCPOL     0  //with synchronous mode only

#define UBRRL    *((volatile u8 *)(0x29))
#define UBRRH    *((volatile u8 *)(0x40))

#define asynchronous 0
#define synchronous  1

#define parity_disabled    0b00
#define reserved           0b01
#define parity_enable_even 0b10
#define parity_enable_odd  0b11
#define one 0
#define two 1

#endif /* UART_DRIVER_UART_PRIVATE_H_ */
