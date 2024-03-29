################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CreatList.cpp \
../DisplayList.cpp \
../Menu.cpp \
../PrintHeader.cpp \
../SearchActor.cpp \
../SearchGenre.cpp \
../SearchRate.cpp \
../SearchTitle.cpp \
../SearchYear.cpp \
../main.cpp 

OBJS += \
./CreatList.o \
./DisplayList.o \
./Menu.o \
./PrintHeader.o \
./SearchActor.o \
./SearchGenre.o \
./SearchRate.o \
./SearchTitle.o \
./SearchYear.o \
./main.o 

CPP_DEPS += \
./CreatList.d \
./DisplayList.d \
./Menu.d \
./PrintHeader.d \
./SearchActor.d \
./SearchGenre.d \
./SearchRate.d \
./SearchTitle.d \
./SearchYear.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


