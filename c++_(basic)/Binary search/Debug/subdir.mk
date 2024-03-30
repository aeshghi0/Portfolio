################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ArrayBinarySearch.cpp \
../ArrayOutput.cpp \
../ArraySequentialSearch.cpp \
../ArraySort.cpp \
../PrintHeader.cpp \
../main.cpp 

OBJS += \
./ArrayBinarySearch.o \
./ArrayOutput.o \
./ArraySequentialSearch.o \
./ArraySort.o \
./PrintHeader.o \
./main.o 

CPP_DEPS += \
./ArrayBinarySearch.d \
./ArrayOutput.d \
./ArraySequentialSearch.d \
./ArraySort.d \
./PrintHeader.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


