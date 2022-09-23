################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CTOS/HAL/CONTROL/CONTROL.c 

OBJS += \
./CTOS/HAL/CONTROL/CONTROL.o 

C_DEPS += \
./CTOS/HAL/CONTROL/CONTROL.d 


# Each subdirectory must supply rules for building sources it contributes
CTOS/HAL/CONTROL/%.o: ../CTOS/HAL/CONTROL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\HAL\Control_Program" -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\SERVICES" -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\HAL\Lights" -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\MCAL\PWM" -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\HAL\FAN" -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\HAL\GAS_SENSOR" -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\HAL\LDR" -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\HAL\LM35" -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\LIB" -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\MCAL\ADC" -I"C:\Users\aweso\Desktop\Hazim\IMT Workspace\Smart_Home_MC2\CTOS\MCAL\DIO" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


