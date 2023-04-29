default_target: all

C_COMPILE_OPTS = -mcpu=cortex-m3 -S -mthumb --specs=nosys.specs
AS_COMPILE_OPTS = -mcpu=cortex-m3
INCLUDE_DIRS = -Iinclude

SOURCE_DIR := src/
BUILD_DIR := build/

SOURCE_FILES = main.c gpio_drive.c

# create C object file
CC = arm-none-eabi-gcc 
CFLAGS = $(C_COMPILE_OPTS) $(INCLUDE_DIRS)

# create assembly object file
AS = arm-none-eabi-as
ASFLAGS = $(AS_COMPILE_OPTS)

# compile elf from objects using linker file
LD = arm-none-eabi-ld 
LDFLAGS = -Tstm32f103.ld

# create binary from elf
OBJCP = arm-none-eabi-objcopy
OBJCPFLAGS = -O binary

all: $(addprefix $(BUILD_DIR),main.s main.o main.elf main.bin)
.PHONY: all

$(BUILD_DIR)main.s: $(SOURCE_DIR)main.c
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)main.o: $(BUILD_DIR)main.s 
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)main.elf: $(BUILD_DIR)main.o
	$(LD) $(LDFLAGS) $< -o $@

$(BUILD_DIR)main.bin: $(BUILD_DIR)main.elf
	$(OBJCP) $(OBJCPFLAGS) $< $@

