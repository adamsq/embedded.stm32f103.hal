#====================================================================#
#Output files
EXECUTABLE=stm32_gpio.elf
BIN_IMAGE=stm32_gpio.bin

#======================================================================#
#Cross Compiler
CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

#======================================================================#
#Flags
CFLAGS=-Wall -g -mlittle-endian -mthumb -nostdlib -ffreestanding
CFLAGS+=-mcpu=cortex-m3
CFLAGS+=-I./
CFLAGS+=-D STM32F103x6

#stm32-flash
CFLAGS+=-Wl,-T,stm32_flash.ld
#======================================================================#
#BSP
BSP_DIR=../../BSP
CFLAGS+=-I$(BSP_DIR)

#HAL
HAL_DIR=../../HAL
CFLAGS+=-I$(HAL_DIR)/Inc

#CMSIS
CMSIS_DIR=../../CMSIS
CFLAGS+=-I$(CMSIS_DIR)/Include
CFLAGS+=-I$(CMSIS_DIR)/Device/ST/STM32F1xx/Include/
#======================================================================#
#setup system clock
SRC=./system_stm32f1xx.c
#HAL_Driver
SRC+=$(HAL_DIR)/Src/stm32f1xx_hal_gpio.c\
	$(HAL_DIR)/Src/stm32f1xx_hal.c\
	$(HAL_DIR)/Src/stm32f1xx_hal_rcc.c\
	$(HAL_DIR)/Src/stm32f1xx_hal_cortex.c \
	

#Major programs
SRC+=./main.c \

#======================================================================#
#STM32 startup file
STARTUP=../Startup/startup_stm32f103x6.s


#======================================================================#
#Make rules

#Make all
all:$(BIN_IMAGE)

$(BIN_IMAGE):$(EXECUTABLE)
	$(OBJCOPY) -O binary $^ $@

STARTUP_OBJ = startup_stm32f103x6.o

$(STARTUP_OBJ): $(STARTUP) 
	$(CC) $(CFLAGS) $^ -c $(STARTUP)

$(EXECUTABLE):$(SRC) $(STARTUP_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

#Make clean
clean:
	rm -rf $(EXECUTABLE)
	rm -rf $(BIN_IMAGE)
#Make flash
flash:
	st-flash write $(BIN_IMAGE) 0x8000000
openocd:
	openocd -f "../commom/openocd.cfg"
gdb:
	arm-none-eabi-gdb -x ../commom/gdb_init.gdb
gdbtui:
	arm-none-eabi-gdb -tui -x ../commom/gdb_init.gdb
#======================================================================
.PHONY:all clean flash
