OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386)
ENTRY(main)
SECTIONS
{
	. = 0x7c00;
	.text.startup : AT(0x7c00)
	{
		*(.text.startup);
	}
	.text :
	{
		*(.text);
	}
	.data :
	{
		*(.data);
		*(.bss);
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
	}
}
