################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/MCAL/DIO/DIO_Program.c 

OBJS += \
./LIB/MCAL/DIO/DIO_Program.o 

C_DEPS += \
./LIB/MCAL/DIO/DIO_Program.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/MCAL/DIO/%.o: ../LIB/MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


