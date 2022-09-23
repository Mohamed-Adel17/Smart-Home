################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CTOS/SERVICES/Scheduler.c 

OBJS += \
./CTOS/SERVICES/Scheduler.o 

C_DEPS += \
./CTOS/SERVICES/Scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
CTOS/SERVICES/%.o: ../CTOS/SERVICES/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI\Smart_Home_MC2\CTOS\MCAL\Inc" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI\Smart_Home_MC2\CTOS\HAL\Inc" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI\Smart_Home_MC2\CTOS\SERVICES" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI\Smart_Home_MC2\CTOS\LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


