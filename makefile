default_target: all

C_COMPILE_OPTS = -mcpu=cortex-m3 -S -mthumb 
AS_COMPILE_OPTS = -mcpu=cortex-m3
INCLUDE_DIRS = -Iinclude

SOURCE_DIR := src/
BUILD_DIR := build/

# create C object file
CC = arm-none-eabi-gcc 
CFLAGS = $(C_COMPILE_OPTS) $(INCLUDE_DIRS)
C_SOURCES = $(wildcard $(SOURCE_DIR)*.c)
C_OBJECTS=build/main.s build/gpio_drive.s build/systick_time.s build/startup.s build/stm32f103.s build/spi_drive.s build/oled_drive.s build/i2c_drive.s

# create assembly object file
AS = arm-none-eabi-as
ASFLAGS = $(AS_COMPILE_OPTS)
AS_SOURCES = $(wildcard $(SOURCE_DIR)*.s)
AS_OBJECTS=build/main.o build/gpio_drive.o build/systick_time.o build/startup.o build/stm32f103.o build/spi_drive.o build/oled_drive.o build/i2c_drive.o

# compile elf from objects using linker file
LD = arm-none-eabi-ld 
LDFLAGS = -Tstm32f103.ld

# create binary from elf
OBJCP = arm-none-eabi-objcopy
OBJCPFLAGS = -O binary

all: $(C_OBJECTS) $(AS_OBJECTS) build/main.elf build/main.bin build/main.list
.PHONY: all

$(C_OBJECTS): $(BUILD_DIR)%.s : $(SOURCE_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@

$(AS_OBJECTS): $(BUILD_DIR)%.o : $(BUILD_DIR)%.s
	$(AS) $(ASFLAGS) $< -o $@

$(BUILD_DIR)main.elf: $(AS_OBJECTS)
	$(LD) $(LDFLAGS) $(AS_OBJECTS) -o $@

$(BUILD_DIR)main.bin: $(BUILD_DIR)main.elf
	$(OBJCP) $(OBJCPFLAGS) $< $@

$(BUILD_DIR)main.list: $(BUILD_DIR)main.elf
	arm-none-eabi-objdump -D build/main.elf > build/main.list
	$(MAKE) clean

clean:
	-rm build/*.o build/*.s
