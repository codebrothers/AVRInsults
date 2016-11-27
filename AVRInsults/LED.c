
void setLED(int on)
{
	if(on>0)
	{
		PORTB |= 1 << PORTB0;
	}
	else
	{
		PORTB &= ~( 1 << PORTB0 );
	}
}

