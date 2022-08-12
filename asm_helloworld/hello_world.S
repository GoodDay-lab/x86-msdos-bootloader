# First option!
# part:
#		.byte 0x55
# 		.byte 0xaa
# MUST BE AT THE END!

# SHIT! I DID IT!
# I SPENT MORE THAN 1,5 days to make HELLO WORLD via asm in bios!
# Lesson #1:
# 		Code starts from _start and no matter that contains first bytes (also "hello, world"),
#			it will be executed.
# Lesson #2:
#  		To get address from label you should use '$' symbol!
#
# Advice #3 (maybe):
#		Better to make out part (adding 2 last bytes) at the end of file, but not necessary
#

.code16
.global _start
.global printk

.text
_start:
	mov $msg, %si
	call main
	jmp out

msg: .asciz "Hello world!\n"
main:
	mov $msg, %si
	call printk
	ret

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

out:
	. = _start + 510
	.byte 0x55
	.byte 0xaa
