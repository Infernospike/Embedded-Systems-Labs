################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/ssp/src/bsp/mcu/s7g2/bsp_cache.c \
../synergy/ssp/src/bsp/mcu/s7g2/bsp_clocks.c \
../synergy/ssp/src/bsp/mcu/s7g2/bsp_feature.c \
../synergy/ssp/src/bsp/mcu/s7g2/bsp_group_irq.c \
../synergy/ssp/src/bsp/mcu/s7g2/bsp_hw_locks.c \
../synergy/ssp/src/bsp/mcu/s7g2/bsp_module_stop.c \
../synergy/ssp/src/bsp/mcu/s7g2/bsp_rom_registers.c 

C_DEPS += \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_cache.d \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_clocks.d \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_feature.d \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_group_irq.d \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_hw_locks.d \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_module_stop.d \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_rom_registers.d 

OBJS += \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_cache.o \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_clocks.o \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_feature.o \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_group_irq.o \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_hw_locks.o \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_module_stop.o \
./synergy/ssp/src/bsp/mcu/s7g2/bsp_rom_registers.o 

SREC += \
UART.srec 

MAP += \
UART.map 


# Each subdirectory must supply rules for building sources it contributes
synergy/ssp/src/bsp/mcu/s7g2/%.o: ../synergy/ssp/src/bsp/mcu/s7g2/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_SYNERGY_ -I"C:/Users/User/e2_studio/workspace/UART/synergy_cfg/ssp_cfg/bsp" -I"C:/Users/User/e2_studio/workspace/UART/synergy_cfg/ssp_cfg/driver" -I"C:/Users/User/e2_studio/workspace/UART/synergy/ssp/inc" -I"C:/Users/User/e2_studio/workspace/UART/synergy/ssp/inc/bsp" -I"C:/Users/User/e2_studio/workspace/UART/synergy/ssp/inc/bsp/cmsis/Include" -I"C:/Users/User/e2_studio/workspace/UART/synergy/ssp/inc/driver/api" -I"C:/Users/User/e2_studio/workspace/UART/synergy/ssp/inc/driver/instances" -I"C:/Users/User/e2_studio/workspace/UART/src" -I"C:/Users/User/e2_studio/workspace/UART/src/synergy_gen" -I"C:/Users/User/e2_studio/workspace/UART/synergy_cfg/ssp_cfg/framework/el" -I"C:/Users/User/e2_studio/workspace/UART/synergy/ssp/inc/framework/el" -I"C:/Users/User/e2_studio/workspace/UART/synergy/ssp/src/framework/el/tx" -I"C:/Users/User/e2_studio/workspace/UART/synergy_cfg/ssp_cfg/framework" -I"C:/Users/User/e2_studio/workspace/UART/synergy/ssp/inc/framework/api" -I"C:/Users/User/e2_studio/workspace/UART/synergy/ssp/inc/framework/instances" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

