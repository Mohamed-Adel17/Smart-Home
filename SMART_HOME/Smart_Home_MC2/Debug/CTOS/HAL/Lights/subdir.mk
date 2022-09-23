################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CTOS/HAL/Lights/Lights.c 

OBJS += \
./CTOS/HAL/Lights/Lights.o 

C_DEPS += \
./CTOS/HAL/Lights/Lights.d 


# Each subdirectory must supply rules for building sources it contributes
CTOS/HAL/Lights/%.o: ../CTOS/HAL/Lights/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC2\CTOS\SERVICES\Scheduler" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC2\CTOS\MCAL\Inc" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC2\CTOS\HAL\Inc" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC2\CTOS\LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


