/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#include "APP.h"
#include "USER/USER.h"
#include "BLINKING/BLINKING.h"

void APP_Init(void)
{
	/* Initialize USER Module */
	USER_Init();
	
	/* Initialize BLINKING Module */
	BLINKING_Init();
}
void APP_Running(void)
{
	/*Update BLINKING */
	BLINKING_Update();
}