################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIMER1/TIMER1_PROGRAM.c 

OBJS += \
./MCAL/TIMER1/TIMER1_PROGRAM.o 

C_DEPS += \
./MCAL/TIMER1/TIMER1_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIMER1/%.o: ../MCAL/TIMER1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC1\MCAL\SPI" -I"D:\ITI embedded training 2022\SDK workspace\Test_Final_ITI_V3\SMART_HOME\Smart_Home_MC1\LIB" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


