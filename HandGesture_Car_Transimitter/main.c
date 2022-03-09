#include "LIB/MCAL/ADC/ADC_Interface.h"
#include "LIB/STD_TYPES.h"
#include "LIB/MCAL/DIO/DIO_Interface.h"
#include "LIB/MCAL/UART/UART_Interface.h"
#include "LIB/HAL/FlexSensor/FLEX_Interface.h"


void main(){

	HFLEX_voidInit();
	ADC_voidInit();
	UART_Init();
	while(1)
	{

		u8 u8_Finger1=HFLEX_u8Getangle(ADC_u8_CHANNEL_0);
		u8 u8_Finger2=HFLEX_u8Getangle(ADC_u8_CHANNEL_1);
		u8 u8_Finger3=HFLEX_u8Getangle(ADC_u8_CHANNEL_2);
		u8 u8_Finger4=HFLEX_u8Getangle(ADC_u8_CHANNEL_3);
		u8 u8_Finger5=HFLEX_u8Getangle(ADC_u8_CHANNEL_4);

		if(u8_Finger1>=90&&u8_Finger2>=90&&u8_Finger3>=90&&u8_Finger4<=5)
		{
			UART_TransmitData('f');

		}

		else if(u8_Finger1<=5&&u8_Finger2>=90&&u8_Finger3>=90&&u8_Finger4>=90)
		{
			UART_TransmitData('r');

		}

		else if(u8_Finger1>=90&&u8_Finger2>=90&&u8_Finger3<=5&&u8_Finger4<=5)
		{
			UART_TransmitData('l');

		}

		else if(u8_Finger1>=90&&u8_Finger2>=90&&u8_Finger3>=90&&u8_Finger4>=90)
		{
			UART_TransmitData('b');

		}
		else if(u8_Finger1<=15&&u8_Finger2<=15&&u8_Finger3<=15&&u8_Finger4<=15)
		{
			UART_TransmitData('s');

		}


	}
}
