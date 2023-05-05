/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#include "SYSTICK.h"
#include "../Utilities.h"

#define NULL 0

cbType callbackPtr = NULL;

/*
 * Function: SYSTICK_cb_register
 * ----------------------------
 *	SYSTICK CallBack Registraion
 *	@param cbType: function ptr
 *	@return void
 */
void SYSTICK_cb_register(cbType ptr)
{
	if(ptr != NULL)
	{
		callbackPtr = ptr;
	}
}

/*
 * Function: SYSTICK_cb_Handler
 * ----------------------------
 *	SYSTICK CallBack Function on OVERFLOW
 *
 *	@return void
 */
static void SYSTICK_cb_Handler(void)
{
	if(callbackPtr != NULL)
	{
		callbackPtr();
	}
}


/*
 * Function: SYSTICK_Wait
 * ----------------------------
 *	Wait in milli Seconds
 *
 *	@param uint32_t timeMS
 *
 *	@return void
 */
void SYSTICK_Wait(uint32_t timeMS)
{
	uint32_t count = 0;
	
	/* Load Value */
	SYSTICK->STRELOAD = SYSTICK_MS;
	
	/* SET CLOCK SOURCE */
	SET_BIT(SYSTICK->STCTRL,SYSTICK_STCTRL_CLKSRC_BIT);
	
	/* ENABLE CLOCK */
	SET_BIT(SYSTICK->STCTRL,SYSTICK_STCTRL_ENABLE_BIT);	
	
	for(count=0; count<timeMS; count++)
	{
		while((SYSTICK->STCTRL & (1U<<SYSTICK_STCTRL_COUNT_BIT)) == 0){}
		
		// OVERFLOW HANDLER
		//SYSTICK_cb_Handler();
	}

	SYSTICK->STCTRL = 0;
	
}