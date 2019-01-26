################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Yakindu/src-gen/Nixie.c 

OBJS += \
./Yakindu/src-gen/Nixie.o 

C_DEPS += \
./Yakindu/src-gen/Nixie.d 


# Each subdirectory must supply rules for building sources it contributes
Yakindu/src-gen/%.o: ../Yakindu/src-gen/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/Users/Manuel/Documents/NixieClock/Inc" -I"C:/Users/Manuel/Documents/NixieClock/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/Manuel/Documents/NixieClock/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Manuel/Documents/NixieClock/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Users/Manuel/Documents/NixieClock/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Users/Manuel/Documents/NixieClock/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"C:/Users/Manuel/Documents/NixieClock/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/Manuel/Documents/NixieClock/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


