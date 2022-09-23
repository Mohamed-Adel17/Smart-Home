################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/main.c 

OBJS += \
./APP/main.o 

C_DEPS += \
./APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC3\HAL\Control_Input" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC3\HAL\KEYPAD" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC3\LIB" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC3\MCAL\DIO" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC3\MCAL\SPI" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


