/*
 * UART_PROGRAM.c
 *
 *  Created on: Oct 29, 2021
 *      Author: Omar Abdalbaset
 */
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "UART_CONFIG.h"
#include "UART_INTERFACE.h"
#include "UART_PRIVATE.h"
 void(* global_UART_Callback[3])(void)={NULL,NULL,NULL};
void UART_INIT(void)
{
//enable and disable interrupt sources
	//1-enable and disable RX Complete
	//2-enable and disable TX Complete
	//3- enable and disable USART Data Register Empty Interrupt
	CLR_BIT(UCSRB,UDRIE);
	CLR_BIT(UCSRB,TXCIE );
	CLR_BIT(UCSRB,RXCIE);
// set character size-> 5,6,7,8
	CLR_BIT(UCSRB,UCSZ2);
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);//THREE SET BIT IN ONE LINE
//select UART mode->sync. or async[UMSEL bit].
#if UART_mode_select==asynchronous
	CLR_BIT(UCSRC,UMSEL);
#elif UART_mode_select==synchronous
	SET_BIT(UCSRC,UMSEL);
#endif
//set parity mode ->disable,even,odd
UCSRC|=(parity_select<<UPM0);
//select stop bit
/*#if (select_stop_bit==one)
CLR_BIT(UCSRC,USBS);
#elif (select_stop_bit==two)
SET_BIT(UCSRC,USBS);
#endif*/

// set clock polarity with sync.only

//set baud rate
//(Fosc/(16*baud_rate))-1
UBRRL=25;
//enable and disable RX,TX
SET_BIT(UCSRB,TXEN);
SET_BIT(UCSRB,RXEN);
}
void UART_Send(u8 data)//polling function
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;

}
u8 UART_Recieve(void)//polling function
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) );
	/* Get and return received data from buffer */
	return UDR;
}
void UART_PrintString(char str[])
{
	for(u8 i=0;str[i]!='\0';i++)
	{
		UART_Send(str[i]);
	}
}
void UART_RecieveString(char str[],u8 size)//polling function
{
	u8 flag=0;
	for(u8 i=0;i<size;i++)
	{
		str[i]=UART_Recieve();
		if(str[i]=='\n')//to be able to recieve string less than size od strinn size
		{
			flag=1;
			str[i]='\0';//to close the string
			break;
		}
	}
	if(flag==0)
	{
		str[size-1]='\0';
	}

}
void UART_EnableInterrupt(u8 IntId)
{

}
void UART_DisableInterrupt(u8 IntId)
{

}
void UART_SetBaudRate(u16 baud_rate)
{
	UBRRL=25;
}
void UART_SetCallBack(u8 IntId,void(*fptr)(void))
{
	switch(IntId)
	{
	case 0:
		global_UART_Callback[0]=fptr;
		break;
	case 1:
		global_UART_Callback[1]=fptr;
		break;
	case 2:
		global_UART_Callback[2]=fptr;
		break;

	}
}
void __vector_13(void) __attribute__ ((signal));//recevie complete
void __vector_13(void)
{
	if(global_UART_Callback[0]!=NULL)
	{
		global_UART_Callback[0]();
	}

}
void __vector_14(void) __attribute__ ((signal));//data reg.empty
void __vector_14(void)
{
	if(global_UART_Callback[1]!=NULL)
		{
			global_UART_Callback[1]();
		}

}
void __vector_15(void) __attribute__ ((signal));//transmit complete
void __vector_15(void)
{
	if(global_UART_Callback[2]!=NULL)
		{
			global_UART_Callback[2]();
		}
}
u8 UART_GetUDR(void)
{
	return UDR;
}
