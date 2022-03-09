#include "LIB/MCAL/ADC/ADC_Interface.h"
#include "LIB/STD_TYPES.h"
#include "LIB/MCAL/DIO/DIO_Interface.h"
#include "LIB/MCAL/UART/UART_Interface.h"
#include "LIB/HAL/FlexSensor/FLEX_Interface.h"
#include "LIB/HAL/LCD/LCD_Interface.h"


void main(){
	MDIO_voidSetPortDirection(DIO_u8_PORTA,DIO_u8_OUTPUT);
	MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN4,DIO_u8_HIGH);
	//ADC_voidInit();
	UART_Init();
	u8 Private_ResievedData;
	while(1)
	{
		Private_ResievedData=UART_RecieveData();

		switch (Private_ResievedData)
		{
			case 'f':
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH); //input 1 high
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW); //input 3 LOW
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);
				HLCD_voidSendString("Forward");
				break;

			case 'b':
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_HIGH);
				HLCD_voidSendString("Backward");
				break;

			case 'l':
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);
				HLCD_voidSendString("Left");
				break;

			case 'r':
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW); //input 3 LOW
				HLCD_voidSendString("Right");
				break;

			case 's':
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_u8_LOW);
				MDIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN3,DIO_u8_LOW);
				HLCD_voidDisplayClear();
				HLCD_voidSendString("Stoped");
				break;

	}
	}
}

