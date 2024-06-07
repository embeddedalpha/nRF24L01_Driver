################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO/GPIO.c 

OBJS += \
./GPIO/GPIO.o 

C_DEPS += \
./GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO/%.o GPIO/%.su GPIO/%.cyclo: ../GPIO/%.c GPIO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/STM32F407_Firmware/NRF24L01_Driver/Console" -I"D:/STM32F407_Firmware/NRF24L01_Driver/DMA" -I"D:/STM32F407_Firmware/NRF24L01_Driver/GPIO" -I"D:/STM32F407_Firmware/NRF24L01_Driver/SPI" -I"D:/STM32F407_Firmware/NRF24L01_Driver/USART" -I"D:/STM32F407_Firmware/NRF24L01_Driver/NRF24L01_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-GPIO

clean-GPIO:
	-$(RM) ./GPIO/GPIO.cyclo ./GPIO/GPIO.d ./GPIO/GPIO.o ./GPIO/GPIO.su

.PHONY: clean-GPIO

