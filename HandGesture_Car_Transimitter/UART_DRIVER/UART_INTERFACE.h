

#ifndef UART_DRIVER_UART_INTERFACE_H_
#define UART_DRIVER_UART_INTERFACE_H_
#include "STD_TYPES.h"
void UART_INIT(void);
void UART_Send(u8 data);//u8 to prevent using 9 bit data mode
u8 UART_Recieve(void);
void UART_PrintString(char str[]);
void UART_RecieveString(char str[],u8 size);
void UART_EnableInterrupt(u8 IntId);
void UART_DisableInterrupt(u8 IntId);
void UART_SetBaudRate(u16 baud_rate);
void UART_SetCallBack(u8 IntId,void(*fptr)(void));
u8 UART_GetUDR(void);


#endif /* UART_DRIVER_UART_INTERFACE_H_ */
