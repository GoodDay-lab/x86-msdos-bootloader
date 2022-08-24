OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386)
ENTRY(main)
SECTIONS
{
	. = 0x7c00;
	.bss :
	{
		*(.bss);
	}
	.text.jump : AT(0x7c00)
	{
		SHORT(0xEB3C);
		BYTE(0x90);
	}
	.info : AT(0x7c03
	{	
		*(.info.oem_name);
		*(.info.bios_param_block.sector_size);
	}
	.text.startup : AT(0x7c3E)
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
