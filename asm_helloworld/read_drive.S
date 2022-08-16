.code16
.global _start

.text
_start:
		xorw %ax, %ax
		movw %ax, %ds
		movw %ax, %es
		movw $0x7e00, %bx
		movw %bx, %si
		

		jmp main

putchar:
        movb $0x0e, %ah
        int $0x10
        ret

printk:
.nextchar:
        movb (%si), %al
        inc %si
        or %al, %al
        jz .printfout
        call putchar
        jmp .nextchar
.printfout:
        ret

readdrive:
		movb $0x02, %ah
		movb $0x01, %al
		movb $0x00, %ch
		movb $0x02, %cl
		movb $0x00, %dh
		int $0x13
		cmpb $0x01, %al
		jne .failure
		ret
.failure:
		int $0x18
		ret
		

main:
		call readdrive
		call printk

out:
		. = _start + 510
		.byte 0x55
		.byte 0xaa
		
