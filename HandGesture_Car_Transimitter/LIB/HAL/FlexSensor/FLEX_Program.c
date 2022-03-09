
#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"

#include "FLEX_Interface.h"
#include "FLEX_Private.h"
#include "FLEX_Configrutaion.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_Private.h"
#include "../../MCAL/DIO/DIO_Configuration.h"

#include "../../MCAL/ADC/ADC_Interface.h"
#include "../../MCAL/ADC/ADC_Private.h"


long Private_map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void HFLEX_voidInit(){
    
     MDIO_voidSetPinDirection(FLEX_SENSOR_PORT,FLEX_SENSOR1_PIN,DIO_u8_INPUT);
     MDIO_voidSetPinDirection(FLEX_SENSOR_PORT,FLEX_SENSOR2_PIN,DIO_u8_INPUT);
     MDIO_voidSetPinDirection(FLEX_SENSOR_PORT,FLEX_SENSOR3_PIN,DIO_u8_INPUT);
     MDIO_voidSetPinDirection(FLEX_SENSOR_PORT,FLEX_SENSOR4_PIN,DIO_u8_INPUT);
     MDIO_voidSetPinDirection(FLEX_SENSOR_PORT,FLEX_SENSOR5_PIN,DIO_u8_INPUT);
}

u8 HFLEX_u8Getangle(u8 copy_FLEX_SENSOR_PIN){

u8 flexADC=ADC_u8GetDigitalValue(copy_FLEX_SENSOR_PIN);

f32 flexR = R_DIV * (VCC /( (flexADC) * VCC / 1023.0) - 1.0);

return Private_map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE,0, 90.0);
    
}
