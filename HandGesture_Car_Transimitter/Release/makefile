################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include LIB/MCAL/UART/subdir.mk
-include LIB/MCAL/DIO/subdir.mk
-include LIB/MCAL/ADC/subdir.mk
-include LIB/HAL/LCD/subdir.mk
-include LIB/HAL/FlexSensor/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
HandGesture_Car_Transmitter.lss \

FLASH_IMAGE += \
HandGesture_Car_Transmitter.hex \

EEPROM_IMAGE += \
HandGesture_Car_Transmitter.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: HandGesture_Car_Transmitter.elf secondary-outputs

# Tool invocations
HandGesture_Car_Transmitter.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,HandGesture_Car_Transmitter.map -mmcu=atmega32 -o "HandGesture_Car_Transmitter.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

HandGesture_Car_Transmitter.lss: HandGesture_Car_Transmitter.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S HandGesture_Car_Transmitter.elf  >"HandGesture_Car_Transmitter.lss"
	@echo 'Finished building: $@'
	@echo ' '

HandGesture_Car_Transmitter.hex: HandGesture_Car_Transmitter.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex HandGesture_Car_Transmitter.elf  "HandGesture_Car_Transmitter.hex"
	@echo 'Finished building: $@'
	@echo ' '

HandGesture_Car_Transmitter.eep: HandGesture_Car_Transmitter.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex HandGesture_Car_Transmitter.elf  "HandGesture_Car_Transmitter.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: HandGesture_Car_Transmitter.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 HandGesture_Car_Transmitter.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) HandGesture_Car_Transmitter.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
