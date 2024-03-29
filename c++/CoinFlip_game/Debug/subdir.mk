################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Average.cpp \
../FlipCoin.cpp \
../GetName.cpp \
../Output.cpp \
../main.cpp 

OBJS += \
./Average.o \
./FlipCoin.o \
./GetName.o \
./Output.o \
./main.o 

CPP_DEPS += \
./Average.d \
./FlipCoin.d \
./GetName.d \
./Output.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


