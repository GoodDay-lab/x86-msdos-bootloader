DRIVE ?= drive.img
FNAME ?= hello_world
TESTSCRIPT ?= qemutest.py

$(DRIVE):
	dd if=/dev/zero of=$@ count=2440 bs=512

%.o: %.S
	$(AS) -o $@ $<

%.bin: %.o
	$(LD) -Ttext 0x7c00 --oformat=binary -o $@ $<

build: $(FNAME).bin
	dd if=$< of=$(DRIVE)

test: $(DRIVE)
	python $(TESTSCRIPT) $(DRIVE)

clean:
	rm -f *.o *.bin 
