DRIVE ?= drive.img
FNAME ?= test.bin
SOURCE ?= read_drive.o
TESTSCRIPT ?= qemutest.py

$(DRIVE):
	dd if=/dev/zero of=$@ count=2440 bs=512

%.o: %.S
	$(AS) -o $@ $<

%.bin: $(SOURCE)
	$(LD) -Ttext 0x7c00 --oformat=binary -o $@ $<

build: $(FNAME)
	dd if=$< of=$(DRIVE)

test: $(DRIVE)
	python $(TESTSCRIPT) $(DRIVE)

clean:
	rm -f *.o *.bin 
