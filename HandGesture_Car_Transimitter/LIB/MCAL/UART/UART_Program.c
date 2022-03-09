
/***************************************************/
/*              Library Directives                 */
/***************************************************/
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

/***************************************************/
/*                 DIO Directives                  */
/***************************************************/
#include "../DIO/DIO_Interface.h"
#include "../DIO/DIO_Private.h"
#include "../DIO/DIO_Configuration.h"

/***************************************************/
/*           	 UART Directives 	               */
/***************************************************/
#include "../UART/UART_Interface.h"
#include "../UART/UART_Private.h"
#include "../UART/UART_Configuration.h"
/***************************************************/
/*          16 Mega Hertz System Frequency          */
/***************************************************/
#define F_CPU   16000000UL

/***************************************************/
/*           		Delay Library   	           */
/***************************************************/
#include <util/delay.h>
/*********************************************************************************************************************************/



//============================================================================================
extern void UART_Init (void)
{

	/*  Store the low byte of the UBBR*/
	UBRRL =  (u8) MyUBRR;

	/*  Store the High byte of the UBBR*/
	UBRRH = (u8)((MyUBRR)>>8);

	/* Configuration of UCSRnA Register  */
	UCSRnA= ( (U2X<<1) | (MPCM<<0) );

	/* Enable Transmit bit(3) and Receive bit(4) in UCSRnC Register */
	UCSRnB = ( (RXEN<<4) | (TXEN<<3) | (UCSZ2<<2) );

	/* Configure UCRnC Register to make 8-bit data & 1 stop bit & no parity  Asynchronous Mode*/
	UCSRnC = ((URSEL << 7) | (UMSEL << 6) | (UPM1 << 5) | (UPM0 << 4)
			| (USBS << 3) | (UCSZ1 << 2) | (UCSZ0 << 1));

	//set_bit(SREG,7);
}

//==================================================================================================
extern void UART_TransmitData (u8 UART_DataToBeSent)
{

	/* So put data in the UDR Register */
	UDR=UART_DataToBeSent;


	 /* check the bit5 (UDRE) is a flag bit to figure that if the UDR register empty or not */
	//while( ! (UCSRnA & (1<<6)) );
	while(GET_BIT(UCSRnA,5)==0);
	//clear the transmit interrupt flag
	SET_BIT(UCSRnA,6);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
extern u8 UART_RecieveData(void)
{
	//while ( ! (UCSRnA & (1<<7)) );
	while(GET_BIT(UCSRnA,7)==0);
	return UDR;

}
//====================================================================================================
extern void UART_voidPrintf(u8 Copy_u8PrintedData[])
{

	u8 iterator=0;

	for (iterator=0;Copy_u8PrintedData[iterator]!='\0';iterator++)
	{
		UART_TransmitData(Copy_u8PrintedData[ iterator]);

	}

}

