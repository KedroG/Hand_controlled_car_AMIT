#include "LIB/MCAL/ADC/ADC_Interface.h"
#include "LIB/STD_TYPES.h"
#include "LIB/MCAL/DIO/DIO_Interface.h"
#include "LIB/MCAL/UART/UART_Interface.h"
#include "LIB/HAL/LCD/LCD_Interface.h"


void main(){
	MDIO_voidSetPortDirection(DIO_u8_PORTA,DIO_u8_OUTPUT);
	MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_HIGH);
	//ADC_voidInit();
	UART_Init();
	u8 Private_ResievedData;
	u8 Private_ScreenDataON=0;
	while(1)
	{
		Private_ResievedData=UART_RecieveData();

		switch (Private_ResievedData)
		{
			case 'f':
				if(Private_ScreenDataON==0){
					HLCD_voidSendString("Forward");
					Private_ScreenDataON=1;
				}
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH); //input 1 high
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW); //input 3 LOW
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);

				break;

			case 'b':
				if(Private_ScreenDataON==0){
					HLCD_voidSendString("Backward");
					Private_ScreenDataON=1;
				}
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);

				break;

			case 'l':
				if(Private_ScreenDataON==0){
					HLCD_voidSendString("Left");
					Private_ScreenDataON=1;
				}
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);

				break;

			case 'r':
				if(Private_ScreenDataON==0){
					HLCD_voidSendString("Right");
					Private_ScreenDataON=1;
				}
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW); //input 3 LOW

				break;

			case 's':

				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);
				HLCD_voidDisplayClear();
				u8 Private_ScreenDataON=0;


				break;

	}
	}
}

