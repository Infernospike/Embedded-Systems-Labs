################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lab6_entry.c \
../src/hal_entry.c 

C_DEPS += \
./src/Lab6_entry.d \
./src/hal_entry.d 

OBJS += \
./src/Lab6_entry.o \
./src/hal_entry.o 

SREC += \
USB.srec 

MAP += \
USB.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_SYNERGY_ -I"C:/Users/User/e2_studio/workspace/USB/src" -I"C:/Users/User/e2_studio/workspace/USB/src/synergy_gen" -I"C:/Users/User/e2_studio/workspace/USB/synergy_cfg/ssp_cfg/bsp" -I"C:/Users/User/e2_studio/workspace/USB/synergy_cfg/ssp_cfg/driver" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/inc" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/inc/bsp" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/inc/bsp/cmsis/Include" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/inc/driver/api" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/inc/driver/instances" -I"C:/Users/User/e2_studio/workspace/USB/synergy_cfg/ssp_cfg/framework/el" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/inc/framework/el" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/src/framework/el/tx" -I"C:/Users/User/e2_studio/workspace/USB/synergy_cfg/ssp_cfg/framework" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/inc/framework/api" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/inc/framework/instances" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/src/framework/el/ux" -I"C:/Users/User/e2_studio/workspace/USB/synergy/ssp/src/framework/el/tx/tx_src" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

