################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitsIoLdd1.c \
../Generated_Code/Bits_Botones.c \
../Generated_Code/CAN1.c \
../Generated_Code/Cpu.c \
../Generated_Code/ECHO.c \
../Generated_Code/FC321.c \
../Generated_Code/Inhr1.c \
../Generated_Code/MCUC1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Pins1.c \
../Generated_Code/RealTimeLdd1.c \
../Generated_Code/TRIGGER.c \
../Generated_Code/TU1.c \
../Generated_Code/Term1.c \
../Generated_Code/WAIT.c 

OBJS += \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitsIoLdd1.o \
./Generated_Code/Bits_Botones.o \
./Generated_Code/CAN1.o \
./Generated_Code/Cpu.o \
./Generated_Code/ECHO.o \
./Generated_Code/FC321.o \
./Generated_Code/Inhr1.o \
./Generated_Code/MCUC1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Pins1.o \
./Generated_Code/RealTimeLdd1.o \
./Generated_Code/TRIGGER.o \
./Generated_Code/TU1.o \
./Generated_Code/Term1.o \
./Generated_Code/WAIT.o 

C_DEPS += \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitsIoLdd1.d \
./Generated_Code/Bits_Botones.d \
./Generated_Code/CAN1.d \
./Generated_Code/Cpu.d \
./Generated_Code/ECHO.d \
./Generated_Code/FC321.d \
./Generated_Code/Inhr1.d \
./Generated_Code/MCUC1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Pins1.d \
./Generated_Code/RealTimeLdd1.d \
./Generated_Code/TRIGGER.d \
./Generated_Code/TU1.d \
./Generated_Code/Term1.d \
./Generated_Code/WAIT.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/bisite/Desktop/SUEM/AlarmEmiter/Static_Code/System" -I"C:/Users/bisite/Desktop/SUEM/AlarmEmiter/Static_Code/PDD" -I"C:/Users/bisite/Desktop/SUEM/AlarmEmiter/Static_Code/IO_Map" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/bisite/Desktop/SUEM/AlarmEmiter/Sources" -I"C:/Users/bisite/Desktop/SUEM/AlarmEmiter/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


