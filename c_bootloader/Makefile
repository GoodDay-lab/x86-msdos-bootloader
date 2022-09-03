BOOT_DRIVE ?= drive.img
DATA_DRIVES ?= second_drive.img
TARGET = test.bin
SOURCE = start.o main.o libc/io.o
PYSCRIPT ?= qemutest.py
CFLAGS ?= -g -Os -ffreestanding -Wall -m16 -fno-pie -fno-stack-protector -I include -l fat16
CFLAGS += -c
ASFLAGS ?= --32
LDFLAGS ?=  -T script.ld -static -nmagic -nostdlib
OBJCOPY ?= objcopy
OBJCOPYFLAGS ?= -O binary

# Some functions can take a lot place, so you can off them
CFLAGS += #-D=_NO_HEX_STDIO_H_

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.S
	$(AS) $(ASFLAGS) -o $@ $<

%.elf: $(SOURCE)
	$(LD) $(LDFLAGS) -o $@ $(SOURCE)

%.bin: %.elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

$(BOOT_DRIVE):
	dd if=/dev/zero of=$@ bs=512 count=2880

build: $(TARGET) $(BOOT_DRIVE)
	dd if=$< of=$(BOOT_DRIVE)

test: $(DRIVE)
	python $(PYSCRIPT) $(BOOT_DRIVE) $(DATA_DRIVES)

clean:
	rm -f *.elf *.bin *.o

