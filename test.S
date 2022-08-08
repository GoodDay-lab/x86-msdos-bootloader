#
# Help me, I can't make a working function that prints strings.
#

.code16
.global _start

.text
_start:
	welcome: .asciz "Hello world!\r\n\0"
	
	xor %dx, %dx	

.writeStringIn:
		movb (welcome), %al
		inc %dx
		cmp $0x05, %dx		# What's wrong?
		je .writeStringOut
		movb $0x0e, %ah
		int $0x10
		jmp .writeStringIn
.writeStringOut:

exit:
		int $0x18
		. = _start + 510
		.byte 0x55
		.byte 0xaa
