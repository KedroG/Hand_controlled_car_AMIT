

#ifndef ADC_H_
#define ADC_H_

#include "ADC_CFG.h"

#define ADC_PIN_0              0
#define ADC_PIN_1              1
#define ADC_PIN_2              2
#define ADC_PIN_3              3
#define ADC_PIN_4              4
#define ADC_PIN_5              5
#define ADC_PIN_6              6
#define ADC_PIN_7              7

#define AREF                   0
#define AVCC                   1
#define NONE                   2
#define IN_256                 3

#define FREE_RUNNING           0
#define ANALOG_COMP            1
#define EXT_INT0               2
#define TIM0_COMP_MAT          3
#define TIM0_OVFL              4
#define TIM_COMP_MATB          5
#define TIM1_OVFL              6
#define TIM1_CAPT_E            7


void ADC_INIT(void);
Uint16 ADC_Read(Uint8 ADC_pin);

#endif /* ADC_H_ */