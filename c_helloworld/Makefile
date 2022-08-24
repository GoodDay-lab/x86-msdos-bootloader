BOOT_DRIVE ?= drive.img
DATA_DRIVES ?= second_drive.img
FNAME = test.bin
SOURCE = main_drive.o libc/stdio.o libc/drive.o
PYSCRIPT ?= qemutest.py
CFLAGS ?= -g -Os -ffreestanding -Wall -m16 -fno-pie -nostdlib -nostdinc -fno-stack-protector
ASFLAGS ?= $(CFLAGS) -S
CFLAGS += -c
LDFLAGS ?=  -T script.ld -static -nmagic -nostdlib
OBJCOPY ?= objcopy
OBJCOPYFLAGS ?= -O binary

# Some functions can take a lot place, so you can off them
CFLAGS += -D=_NO_HEX_STDIO_H_

##########################################
# Sources to build different bootloaders
# (just uncomment them) and 'make build'
##########################################
# To build with graphic:
#SOURCE = main_graphic.o libc/stdio.o
# To build with logo:
#SOURCE = main_logo.o libc/stdio.o libc/logo.o
# To manage with disk:
#SOURCE = main_drive.o libc/drive.o libc/stdio.o

%.S: %.c
	$(CC) $(ASFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.elf: $(SOURCE)
	$(LD) $(LDFLAGS) -o $@ $(SOURCE)

%.bin: %.elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(BOOT_DRIVE):
	dd if=/dev/zero of=$@ bs=512 count=2880

build: $(FNAME) $(BOOT_DRIVE)
	dd if=$< of=$(BOOT_DRIVE)

test: $(DRIVE)
	python $(PYSCRIPT) $(BOOT_DRIVE) $(DATA_DRIVES)

clean:
	rm -f *.elf *.bin *.o

