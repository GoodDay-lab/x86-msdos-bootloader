test.bin: test.S
	as test.S -o test.o
	ld -Ttext 0x7c00 --oformat=binary test.o -o test.bin
	dd if=test.bin of=simplebootld.img

clean:
	rm *.bin -f
	rm *.o -f
