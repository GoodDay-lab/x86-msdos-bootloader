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

	.info.oem_name : AT(0x7c03) { *(.info.oem_name); }
	.info.pbs.sector_size : AT(0x7c0B) { *(.info.pbs.sector_size); }
	.info.pbs.cluster_size : AT(0x7c0D) { *(.info.pbs.cluster_size); }
	.info.pbs.reserved_sectors : AT(0x7c0E) { *(.info.pbs.reserved_sectors); }
	.info.pbs.number_of_fats : AT(0x7c10) { *(.info.pbs.number_of_fats); }
	.info.pbs.root_entries : AT(0x7c11) { *(.info.pbs.root_entries); }
	.info.pbs.small_sectors : AT(0x7c13) { *(.info.pbs.small_sectors); }
	.info.pbs.media_type : AT(0x7c15) { *(.info.pbs.media_type); }
	.info.pbs.sectors_per_fat : AT(0x7c16) { *(.info.pbs.sectors_per_fat); }
	.info.pbs.sectors_per_track : AT(0x7c18) { *(.info.pbs.sectors_per_track); }
	.info.pbs.number_of_heads : AT(0x7c1A) { *(.info.pbs.number_of_heads); }
	.info.pbs.hidden_sectors : AT(0x7c1C) { *(.info.pbs.hidden_sectors); }
	.info.pbs.large_sectors : AT(0x7c20) { *(.info.pbs.large_sectors); }

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
