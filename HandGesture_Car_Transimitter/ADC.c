
#include "ADC.h"

void ADC_INIT(void)
{
	/*Voltage Reference*/
	ADMUX = (ADC_SOURCE << 6) | (ADMUX & 0x3F);
	/*Right ADJUST*/
	Clear_Bit(ADMUX, 5);
	/*128 Prescaler*/
	ADCSRA = 0x07;	
	/*Conversion Mode: AutoTrigger/FreeRunning*/
	Clear_Bit(ADCSRA, 5);
	SFIOR = (AUTO_TRIGGER_MODE << 5) | (SFIOR & 0x1F);
	/*ADC peripheral Enable*/
	Set_Bit(ADCSRA, 7);
}
Uint16 ADC_Read(Uint8 ADC_pin)
{
	/*Channel select*/
	ADMUX = ADC_pin | (ADMUX & 0xE0);
	/*Start of conversion*/
	Set_Bit(ADCSRA, 6);
	/*End of conversion Polling*/
	while(Get_Bit(ADCSRA, 4) == 0);
	/*Converted digital output*/
	Uint16 DigitalOutput = ADCRA;
	return DigitalOutput;
}
