

#if EXT_MEM == EXT_MEM_PGMSPACE

void memcpy_E( ADDRESS_E src, char* dst, size_t size )
{
	//memcpy_P()
}

ADDRESS_E ext_read_address( ADDRESS_E address )
{

}

char ext_read_byte( ADDRESS_E address )
{

}

#elif EXT_MEM == EXT_MEM_SPIEEPROM

void memcpy_E( ADDRESS_E src, char* dst, size_t size )
{
	//TODO: SPI EEPROM read
}

ADDRESS_E ext_read_address( ADDRESS_E address )
{
	//TODO: SPI EEPROM 16-bit address read
}

char ext_read_byte( ADDRESS_E address )
{
	//TODO: SPI EEPROM 8-bit byte read
}

#else
#error No external memory implementation defined
#endif

