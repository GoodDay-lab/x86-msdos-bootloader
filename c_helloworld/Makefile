DRIVE ?= drive.img
FNAME = test.bin
SOURCE = code.o stdio.o
PYSCRIPT ?= qemutest.py
CFLAGS ?= -c -g -Os -ffreestanding -Wall -m16 -fno-pie -nostdlib -nostdinc
LDFLAGS ?=  -T script.ld -static -nmagic -nostdlib -s -L.

OBJCOPY ?= objcopy
OBJCOPYFLAGS ?= -O binary

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

