OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386)
SECTIONS
{
	.bss : AT(0x7000) { *(.bss); }
	.text.start : AT(0x7c00)
	{
		*(.text.start);
	}
        .text : AT(0x7c3e)
        {
                *(.text*);
        }
	.data :
	{
		*(.data);
		*(.rodata*);
	}
	.sig : AT(0x7DFE)
	{
		SHORT(0xaa55);
	}
	/DISCARD/ :
	{
		*(.comment);
		*(.note*);
		*(.eh_frame);
                *(.debug*);
	}
}
