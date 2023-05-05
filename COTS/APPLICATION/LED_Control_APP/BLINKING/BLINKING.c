#include "BLINKING.h"
#include "../SERVICES/DISPLAY/DISPLAY.h"
#include "../SERVICES/TIME/TIME.h"

uint8_t onTime = INITIAL_ON_VALUE;
uint8_t offTime = INITIAL_OFF_VALUE;

void BLINKING_Init(void)
{	
	/* LEDS Initialization */
	DISPLAY_Init(LED_USER);
}
void BLINKING_Update(void)
{
	/* DISPLAY ON */
	DISPLAY_ON(LED_USER);
	
	/* DELAY ON PERIOD */
	TIME_Wait_Seconds(onTime);

	/* DISPLAY OFF */
	DISPLAY_OFF(LED_USER);
	
	/* DELAY OFF PERIOD */
	TIME_Wait_Seconds(offTime);
}