################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/HAL/LCD/LCD_Program.c 

OBJS += \
./LIB/HAL/LCD/LCD_Program.o 

C_DEPS += \
./LIB/HAL/LCD/LCD_Program.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/HAL/LCD/%.o: ../LIB/HAL/LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


