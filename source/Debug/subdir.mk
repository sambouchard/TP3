################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Adresse.cpp \
../Candidat.cpp \
../Circonscription.cpp \
../ContratException.cpp \
../Date.cpp \
../Electeur.cpp \
../Personne.cpp \
../Principal.cpp \
../validationFormat.cpp 

OBJS += \
./Adresse.o \
./Candidat.o \
./Circonscription.o \
./ContratException.o \
./Date.o \
./Electeur.o \
./Personne.o \
./Principal.o \
./validationFormat.o 

CPP_DEPS += \
./Adresse.d \
./Candidat.d \
./Circonscription.d \
./ContratException.d \
./Date.d \
./Electeur.d \
./Personne.d \
./Principal.d \
./validationFormat.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++03 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


