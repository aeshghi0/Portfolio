################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CheckWin.cpp \
../DisplayBoard.cpp \
../GetAndCheckInp.cpp \
../GetPlayers.cpp \
../InitBoard.cpp \
../OutputInstruct.cpp \
../OutputWinner.cpp \
../SwitchToken.cpp \
../main.cpp \
../printHeader.cpp 

OBJS += \
./CheckWin.o \
./DisplayBoard.o \
./GetAndCheckInp.o \
./GetPlayers.o \
./InitBoard.o \
./OutputInstruct.o \
./OutputWinner.o \
./SwitchToken.o \
./main.o \
./printHeader.o 

CPP_DEPS += \
./CheckWin.d \
./DisplayBoard.d \
./GetAndCheckInp.d \
./GetPlayers.d \
./InitBoard.d \
./OutputInstruct.d \
./OutputWinner.d \
./SwitchToken.d \
./main.d \
./printHeader.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


