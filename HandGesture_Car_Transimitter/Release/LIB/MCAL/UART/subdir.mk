################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/MCAL/UART/UART_Program.c 

OBJS += \
./LIB/MCAL/UART/UART_Program.o 

C_DEPS += \
./LIB/MCAL/UART/UART_Program.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/MCAL/UART/%.o: ../LIB/MCAL/UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

