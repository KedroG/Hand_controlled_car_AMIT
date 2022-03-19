
#include <util/delay.h>

#include "ADC.h"
#include "DIO.h"
#include "UART_DRIVER/UART_INTERFACE.h"



int main()
{
 	float finger1 = 0;
 	float finger2 = 0;
 	float finger3 = 0;
 	float finger4 = 0;
 	float finger5 = 0;


	ADC_INIT();
	DIO_SetPinDir(DIO_PORTC,DIO_PIN_2,DIO_PIN_OUT);
	UART_INIT();

	while(1)
	{
		finger1 = (ADC_Read(ADC_PIN_0));
		finger2 = (ADC_Read(ADC_PIN_1));
		finger3 = (ADC_Read(ADC_PIN_2));
		finger4 = (ADC_Read(ADC_PIN_3));
		finger5 = (ADC_Read(ADC_PIN_4));

		if (finger1<=500&&finger2<=500&&finger3<=500&&finger4>=500) {
					DIO_SetPinVal(DIO_PORTC,DIO_PIN_2,DIO_PIN_ON);
					UART_Send('f');
				}

		else if (finger1<=500&&finger2<=500&&finger3<=500&&finger4<=500) {
					DIO_SetPinVal(DIO_PORTC,DIO_PIN_2,DIO_PIN_ON);
					UART_Send('b');
				}


		else if (finger1>=500&&finger2<=500&&finger3<=500&&finger4<=500) {
					DIO_SetPinVal(DIO_PORTC,DIO_PIN_2,DIO_PIN_ON);
					UART_Send('r');
		}

		else if (finger1<=500&&finger2<=500&&finger3>=500&&finger4>=500) {
					DIO_SetPinVal(DIO_PORTC,DIO_PIN_2,DIO_PIN_ON);
					UART_Send('l');
		}

		else if (finger1<=500&&finger2<=500&&finger3<=500&&finger4<=500) {
					DIO_SetPinVal(DIO_PORTC,DIO_PIN_2,DIO_PIN_ON);
					UART_Send('s');
		}

		else {
					DIO_SetPinVal(DIO_PORTC,DIO_PIN_2,DIO_PIN_OFF);
					UART_Send('s');
			}

		_delay_ms(200);

	}

}


