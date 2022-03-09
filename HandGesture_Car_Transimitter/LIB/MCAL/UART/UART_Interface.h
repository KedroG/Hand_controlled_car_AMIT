

#ifndef INCLUDE_MCAL_UART_UART_INTERFACE_H_
#define INCLUDE_MCAL_UART_UART_INTERFACE_H_

void UART_Init (void);
extern void UART_TransmitData (u8 UART_DataToBeSent);
extern u8 UART_RecieveData(void);
extern void UART_voidPrintf(u8 Copy_u8PrintedData[]);

#endif /* INCLUDE_MCAL_UART_UART_INTERFACE_H_ */
