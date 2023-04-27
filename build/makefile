default_target: all

C_COMPILE_OPTS = -mcpu=cortex-m3 -S -mthumb --specs=nosys.specs
AS_COMPILE_OPTS = -mcpu=cortex-m3
INCLUDE_DIRS = -I . -I ../include 

# create C object file
CC = arm-none-eabi-gcc 
CFLAGS = $(C_COMPILE_OPTS) $(INCLUDE_DIRS)

# create assembly object file
AS = arm-none-eabi-as
ASFLAGS = $(AS_COMPILE_OPTS)

# compile elf from objects using linker file
LD = arm-none-eabi-ld 
LDFLAGS = -T flash.ld

# create binary from elf
OBJCP = arm-none-eabi-objcopy
OBJCPFLAGS = -O binary

all: main.o main.elf main.bin

main.s: main.c
	$(CC) $(CFLAGS) main.c -o $@

main.o: main.s 
	$(AS) $(ASFLAGS) main.s -o $@

main.elf: main.s
	$(LD) $(LDFLAGS) main.o -o main.elf 

main.bin: main.elf
	$(OBJCP) $(OBJCPFLAGS) $< $@

