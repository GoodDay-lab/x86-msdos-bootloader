DRIVE ?= drive.img
FNAME = test.bin
SOURCE = main_drive.o stdio.o drive.o
PYSCRIPT ?= qemutest.py
CFLAGS ?= -c -g -Os -ffreestanding -Wall -m16 -fno-pie -nostdlib -nostdinc
LDFLAGS ?=  -T script.ld -static -nmagic -nostdlib -s -L.
OBJCOPY ?= objcopy
OBJCOPYFLAGS ?= -O binary

##########################################
# Sources to build different bootloaders
# (just uncomment them) and 'make build'
##########################################
# To build with graphic:
#SOURCE = main_graphic.o stdio.o draw.o
# To build with logo:
#SOURCE = main_logo.o stdio.o logo.o

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

