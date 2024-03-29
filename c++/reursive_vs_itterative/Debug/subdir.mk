################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CheckInpFact.cpp \
../Fact.cpp \
../FactLoop.cpp \
../GetCheckInp.cpp \
../Menu.cpp \
../PrintHeader.cpp \
../SeriesFib.cpp \
../SeriesFibLoop.cpp \
../main.cpp 

OBJS += \
./CheckInpFact.o \
./Fact.o \
./FactLoop.o \
./GetCheckInp.o \
./Menu.o \
./PrintHeader.o \
./SeriesFib.o \
./SeriesFibLoop.o \
./main.o 

CPP_DEPS += \
./CheckInpFact.d \
./Fact.d \
./FactLoop.d \
./GetCheckInp.d \
./Menu.d \
./PrintHeader.d \
./SeriesFib.d \
./SeriesFibLoop.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DGLIBCXX_USE_C99_STDINT_TR1 -D"__cplusplus= 201103L" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


