# setup
COMPILE_OPTS = -mcpu=cortex-m3 -mthumb -Wall -g -O0
INCLUDE_DIRS = -I . -I ../include

CC = arm-none-eabi-gcc
CFLAGS = $(COMPILE_OPTS) $(INCLUDE_DIRS)

CXX = arm-none-eabi-g++
CXXFLAGS = $(COMPILE_OPTS) $(INCLUDE_DIRS)

AS = arm-none-eabi-gcc
ASFLAGS = $(COMPILE_OPTS) -c

LD = arm-none-eabi-gcc
LDFLAGS = -Wl,--gc-sections,-Map=$@.map,-cref,-u,Reset_Handler  --specs=nosys.specs $(INCLUDE_DIRS)

OBJCP = arm-none-eabi-objcopy
OBJCPFLAGS = -O binary

AR = arm-none-eabi-ar
ARFLAGS = cr

MAIN_OUT = main
MAIN_OUT_ELF = $(MAIN_OUT).elf
MAIN_OUT_BIN = $(MAIN_OUT).bin

# all
all: $(MAIN_OUT_ELF) $(MAIN_OUT_BIN)

# main
$(MAIN_OUT_ELF): main.o 
	$(LD) $(LDFLAGS) main.o  --output $@

$(MAIN_OUT_BIN): $(MAIN_OUT_ELF)
	$(OBJCP) $(OBJCPFLAGS) $< $@

clean:
	-rm *.o src/*.o  $(MAIN_OUT_ELF) $(MAIN_OUT_BIN)


