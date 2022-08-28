OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386)
ENTRY(main)
SECTIONS
{
	.bss : AT(0x7b00) { *(.bss); }
	.text : AT(0x7c00)
	{
		*(.text.startup);
		*(.text);
	}
	.data :
	{
		*(.data);
		*(.rodata*);
	}
	.table : AT(0x7DBE)
	{
		*(.table);
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
