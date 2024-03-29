################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ChangeAge.cpp \
../ChangeValue.cpp \
../Display.cpp \
../FirstMenu.cpp \
../Initialize.cpp \
../Menu.cpp \
../PrintHeader.cpp \
../main.cpp 

OBJS += \
./ChangeAge.o \
./ChangeValue.o \
./Display.o \
./FirstMenu.o \
./Initialize.o \
./Menu.o \
./PrintHeader.o \
./main.o 

CPP_DEPS += \
./ChangeAge.d \
./ChangeValue.d \
./Display.d \
./FirstMenu.d \
./Initialize.d \
./Menu.d \
./PrintHeader.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


