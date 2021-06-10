################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Yakindu/src-gen/Nixie.c 

OBJS += \
./Yakindu/src-gen/Nixie.o 

C_DEPS += \
./Yakindu/src-gen/Nixie.d 


# Each subdirectory must supply rules for building sources it contributes
Yakindu/src-gen/Nixie.o: ../Yakindu/src-gen/Nixie.c Yakindu/src-gen/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"Yakindu/src-gen/Nixie.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

