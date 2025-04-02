################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/ssp/src/driver/r_icu/r_icu.c 

C_DEPS += \
./synergy/ssp/src/driver/r_icu/r_icu.d 

OBJS += \
./synergy/ssp/src/driver/r_icu/r_icu.o 

SREC += \
Blinky.srec 

MAP += \
Blinky.map 


# Each subdirectory must supply rules for building sources it contributes
synergy/ssp/src/driver/r_icu/%.o: ../synergy/ssp/src/driver/r_icu/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-strict-aliasing -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal -g -D_RENESAS_SYNERGY_ -I"C:/Users/User/e2_studio/workspace/Blinky/src" -I"C:/Users/User/e2_studio/workspace/Blinky/src/synergy_gen" -I"C:/Users/User/e2_studio/workspace/Blinky/synergy_cfg/ssp_cfg/bsp" -I"C:/Users/User/e2_studio/workspace/Blinky/synergy_cfg/ssp_cfg/driver" -I"C:/Users/User/e2_studio/workspace/Blinky/synergy/ssp/inc" -I"C:/Users/User/e2_studio/workspace/Blinky/synergy/ssp/inc/bsp" -I"C:/Users/User/e2_studio/workspace/Blinky/synergy/ssp/inc/bsp/cmsis/Include" -I"C:/Users/User/e2_studio/workspace/Blinky/synergy/ssp/inc/driver/api" -I"C:/Users/User/e2_studio/workspace/Blinky/synergy/ssp/inc/driver/instances" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

