################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../GreatestCommonDivisor.cpp \
../OutputResults.cpp \
../PrintHeaderFile.cpp \
../PrintHeaderScreen.cpp \
../ReadTwoInts.cpp \
../main.cpp 

OBJS += \
./GreatestCommonDivisor.o \
./OutputResults.o \
./PrintHeaderFile.o \
./PrintHeaderScreen.o \
./ReadTwoInts.o \
./main.o 

CPP_DEPS += \
./GreatestCommonDivisor.d \
./OutputResults.d \
./PrintHeaderFile.d \
./PrintHeaderScreen.d \
./ReadTwoInts.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


