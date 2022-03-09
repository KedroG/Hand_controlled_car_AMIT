################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LIB/MCAL/UART_DRIVER/UART_PROGRAM.c 

OBJS += \
./LIB/MCAL/UART_DRIVER/UART_PROGRAM.o 

C_DEPS += \
./LIB/MCAL/UART_DRIVER/UART_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
LIB/MCAL/UART_DRIVER/%.o: ../LIB/MCAL/UART_DRIVER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=attiny84 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


