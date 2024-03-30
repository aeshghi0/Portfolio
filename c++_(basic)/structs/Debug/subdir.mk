################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BalanceSearch.cpp \
../FileOutput.cpp \
../Input.cpp \
../PrintHeader.cpp \
../SearchName.cpp \
../SumAndAvg.cpp \
../main.cpp 

OBJS += \
./BalanceSearch.o \
./FileOutput.o \
./Input.o \
./PrintHeader.o \
./SearchName.o \
./SumAndAvg.o \
./main.o 

CPP_DEPS += \
./BalanceSearch.d \
./FileOutput.d \
./Input.d \
./PrintHeader.d \
./SearchName.d \
./SumAndAvg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


