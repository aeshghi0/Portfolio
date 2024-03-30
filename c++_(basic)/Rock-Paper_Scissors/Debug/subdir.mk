################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CheckWin.cpp \
../GetAndCheckPlay.cpp \
../GetCompPlay.cpp \
../GetInput.cpp \
../OutpuMatchWinner.cpp \
../OutputWin.cpp \
../maun.cpp 

OBJS += \
./CheckWin.o \
./GetAndCheckPlay.o \
./GetCompPlay.o \
./GetInput.o \
./OutpuMatchWinner.o \
./OutputWin.o \
./maun.o 

CPP_DEPS += \
./CheckWin.d \
./GetAndCheckPlay.d \
./GetCompPlay.d \
./GetInput.d \
./OutpuMatchWinner.d \
./OutputWin.d \
./maun.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


