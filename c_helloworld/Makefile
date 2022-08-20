DRIVE ?= drive.img
FNAME = test.bin
SOURCE = main_drive.o libc/stdio.o libc/drive.o
PYSCRIPT ?= qemutest.py
CFLAGS ?= -g -Os -ffreestanding -Wall -m16 -fno-pie -nostdlib -nostdinc
ASFLAGS ?= $(CFLAGS) -S
CFLAGS += -c
LDFLAGS ?=  -T script.ld -static -nmagic -nostdlib -s
OBJCOPY ?= objcopy
OBJCOPYFLAGS ?= -O binary

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

$(DRIVE):
	dd if=/dev/zero of=$@ bs=512 count=2880

build: $(FNAME) $(DRIVE)
	dd if=$< of=$(DRIVE)

test: $(DRIVE)
	python $(PYSCRIPT) $(DRIVE)

clean:
	rm -f *.elf *.bin *.o

