################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USART/USART.c 

OBJS += \
./USART/USART.o 

C_DEPS += \
./USART/USART.d 


# Each subdirectory must supply rules for building sources it contributes
USART/%.o USART/%.su USART/%.cyclo: ../USART/%.c USART/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/STM32F407_Firmware/NRF24L01_Driver/Console" -I"D:/STM32F407_Firmware/NRF24L01_Driver/DMA" -I"D:/STM32F407_Firmware/NRF24L01_Driver/GPIO" -I"D:/STM32F407_Firmware/NRF24L01_Driver/SPI" -I"D:/STM32F407_Firmware/NRF24L01_Driver/USART" -I"D:/STM32F407_Firmware/NRF24L01_Driver/NRF24L01_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-USART

clean-USART:
	-$(RM) ./USART/USART.cyclo ./USART/USART.d ./USART/USART.o ./USART/USART.su

.PHONY: clean-USART

