#
# A simple makefile for building program composed of C/asm source files.
# Builds for ARM target using cross-development toolchain. 
#

# Set variables to correct tools
ARMGNU = arm-none-eabi
CC = $(ARMGNU)-gcc
AS = $(ARMGNU)-as
OBJCOPY = $(ARMGNU)-objcopy
OBJDUMP = $(ARMGNU)-objdump

# Configure compile options via CFLAGS
#  -g        	compile with debug information
#  -Wall     	give verbose compiler warnings
#  -Og       	apply moderate optimization, retain structure for debugging
#  -std=c99  	use the C99 standard language definition
#  -ffreestanding	do not assume presence of standard library (non-hosted)
CFLAGS = -g -Wall -Og -std=c99 -ffreestanding

# Configure linker options via LDFLAGS, LDLIBS
#  -nostdlib   	do not link standard system startup nor default libraries
#  -T memmap    use our linker map
LDFLAGS = -nostdlib -lgcc -T memmap
LDLIBS =


# Set name of the executable, built from single source file 'name.c'
# Edit here to change executable name or add/remove/change source files
NAME = clock
SOURCES = $(NAME).c
OBJECTS = $(SOURCES:.c=.o)


# The first target listed in the makefile is the default product built when
# make is invoked with no argument
all : $(NAME).bin

# Link object files into elf executable, use custom start.o in place of default
$(NAME).elf: start.o $(OBJECTS)
	$(CC) -o $@  $^ $(LDFLAGS) $(LDLIBS)

# The install target uploads freshly made binary image to rpi bootloader
install: $(NAME).bin
	rpi-install.py $(NAME).bin

# This pattern rule creates binary 'name.bin' by extracting raw instructions 
# from executable 'name.elf'
%.bin: %.elf
	$(OBJCOPY) $< -O binary $@

# This pattern rule produces 'name.list' assembly listing by disassembling 'name.o'
%.list: %.o
	$(OBJDUMP) -d $< > $@

# These 2 pattern rules not truly necessary, just make explicit what was implicit...
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

# The clean target removes previous build products, will force build a-new on next make
clean:
	rm -f *.o *.bin *.elf *.list

# Targets that aren't filename of build product should be declared "phony" 
.PHONY: all clean
