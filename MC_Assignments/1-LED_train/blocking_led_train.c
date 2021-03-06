#include "main.h"

void blocking_led_train(void)
{
		//Loop 32 times to have back and forth blinking
		static unsigned short i = 0;
		//Turn OFF LEDs in opposite direction
		if (i > 23)
				LED_ARRAY &= ~(01 << 31 - i);
		//Turn ON LEDs in opposite direction
		else if (i > 15)
				LED_ARRAY |= (01 << 23 - i);
		//Turn OFF LEDs in forward direction
		else if (i > 7)
				LED_ARRAY &= ~(01 << i - 8);
		//Turn ON LEDs in forward direction
		else
				LED_ARRAY |= (01 << i);
		//Provide a delay to make the output visible to human eyes
		//Use of volatile prevents delay count from getting optimized
		for (volatile unsigned short i = 50000; i--;);
		if (++i == 32)
				i = 0;
}

