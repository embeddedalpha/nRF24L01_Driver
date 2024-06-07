################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NRF24L01_Driver/NRF24L01.c 

OBJS += \
./NRF24L01_Driver/NRF24L01.o 

C_DEPS += \
./NRF24L01_Driver/NRF24L01.d 


# Each subdirectory must supply rules for building sources it contributes
NRF24L01_Driver/%.o NRF24L01_Driver/%.su NRF24L01_Driver/%.cyclo: ../NRF24L01_Driver/%.c NRF24L01_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"D:/STM32F407_Firmware/NRF24L01_Driver/Console" -I"D:/STM32F407_Firmware/NRF24L01_Driver/DMA" -I"D:/STM32F407_Firmware/NRF24L01_Driver/GPIO" -I"D:/STM32F407_Firmware/NRF24L01_Driver/SPI" -I"D:/STM32F407_Firmware/NRF24L01_Driver/USART" -I"D:/STM32F407_Firmware/NRF24L01_Driver/NRF24L01_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-NRF24L01_Driver

clean-NRF24L01_Driver:
	-$(RM) ./NRF24L01_Driver/NRF24L01.cyclo ./NRF24L01_Driver/NRF24L01.d ./NRF24L01_Driver/NRF24L01.o ./NRF24L01_Driver/NRF24L01.su

.PHONY: clean-NRF24L01_Driver

