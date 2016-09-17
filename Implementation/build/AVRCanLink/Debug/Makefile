################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/avr_isr_vectors.c \
../src/can_application.c \
../src/can_driver.c \
../src/can_midleware.c \
../src/hardware_init.c \
../src/Indicator_Driver.c \
../src/main.c \
../src/print_functions.c \
../src/schedule_callbacks.c \
../src/system_callbacks.c \
../src/task_scheduler.c \
../src/timers_at90can128.c \
../src/twi_at90can128.c \
../src/usart.c \
../src/watchdog.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
src/avr_isr_vectors.o \
src/can_application.o \
src/can_driver.o \
src/can_midleware.o \
src/hardware_init.o \
src/Indicator_Driver.o \
src/main.o \
src/print_functions.o \
src/schedule_callbacks.o \
src/system_callbacks.o \
src/task_scheduler.o \
src/timers_at90can128.o \
src/twi_at90can128.o \
src/usart.o \
src/watchdog.o

OBJS_AS_ARGS +=  \
src/avr_isr_vectors.o \
src/can_application.o \
src/can_driver.o \
src/can_midleware.o \
src/hardware_init.o \
src/Indicator_Driver.o \
src/main.o \
src/print_functions.o \
src/schedule_callbacks.o \
src/system_callbacks.o \
src/task_scheduler.o \
src/timers_at90can128.o \
src/twi_at90can128.o \
src/usart.o \
src/watchdog.o

C_DEPS +=  \
src/avr_isr_vectors.d \
src/can_application.d \
src/can_driver.d \
src/can_midleware.d \
src/hardware_init.d \
src/Indicator_Driver.d \
src/main.d \
src/print_functions.d \
src/schedule_callbacks.d \
src/system_callbacks.d \
src/task_scheduler.d \
src/timers_at90can128.d \
src/twi_at90can128.d \
src/usart.d \
src/watchdog.d

C_DEPS_AS_ARGS +=  \
src/avr_isr_vectors.d \
src/can_application.d \
src/can_driver.d \
src/can_midleware.d \
src/hardware_init.d \
src/Indicator_Driver.d \
src/main.d \
src/print_functions.d \
src/schedule_callbacks.d \
src/system_callbacks.d \
src/task_scheduler.d \
src/timers_at90can128.d \
src/twi_at90can128.d \
src/usart.d \
src/watchdog.d

OUTPUT_FILE_PATH +=AVRCanLink.elf

OUTPUT_FILE_PATH_AS_ARGS +=AVRCanLink.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler































src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"../src"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=at90can128 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 4.8.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="AVRCanLink.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=at90can128  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "AVRCanLink.elf" "AVRCanLink.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "AVRCanLink.elf" "AVRCanLink.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "AVRCanLink.elf" > "AVRCanLink.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "AVRCanLink.elf" "AVRCanLink.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.1061\avr8-gnu-toolchain\bin\avr-size.exe" "AVRCanLink.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "AVRCanLink.elf" "AVRCanLink.a" "AVRCanLink.hex" "AVRCanLink.lss" "AVRCanLink.eep" "AVRCanLink.map" "AVRCanLink.srec" "AVRCanLink.usersignatures"
	