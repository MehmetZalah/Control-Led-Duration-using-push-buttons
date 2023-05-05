#include "USER.h"
#include "../SERVICES/INPUT/INPUT.h"
#include "stdint.h"

#define USER_Handler GPIOF_Handler

#define EMPTY_VALUE 0

extern uint8_t onTime;
extern uint8_t offTime;

uint8_t onTemp = EMPTY_VALUE;
uint8_t offTemp = EMPTY_VALUE;


/*
 * Function: USER_Init
 * ----------------------------
 *	USER Module Initialization Function
 *
 *		@return void
 */
void USER_Init(void)
{
	/* BUTTONS */
	INPUT_Init(INPUT_ONSWITCH);
	INPUT_Init(INPUT_OFFSWITCH);
}


/*
 * Function: USER_Handler
 * ----------------------------
 *	interrupt handler function for PORT F
 *
 *		@return void
 */
void USER_Handler(void)
{
	// Check IF ON_SWITCH PRESSED
	if(INPUT_GetState(INPUT_ONSWITCH) == INPUT_STATE_PRESSED)
	{
		// Clear Interrupt Flag
		INPUT_ClearFlag(INPUT_ONSWITCH);
		
		// IF off count has value means confirm OFF state
		if(offTemp != EMPTY_VALUE)
		{
			/* Confirm State */
			offTime = offTemp;
			
			/* RESET TEMP */
			offTemp = EMPTY_VALUE;
			onTemp = EMPTY_VALUE;
		}
		else
		{
			/* Increment ON_PERIOD */
			onTemp++;
		}
		
			
	} // Check IF OFF_SWITCH PRESSED
	else if(INPUT_GetState(INPUT_OFFSWITCH) == INPUT_STATE_PRESSED)
	{
		// Clear Interrupt Flag
		INPUT_ClearFlag(INPUT_OFFSWITCH);
		
		// IF on count has value means confirm ON state
		if(onTemp != EMPTY_VALUE)
		{
			/* Confirm State */
			onTime = onTemp;
			
			/* RESET TEMP */
			offTemp = EMPTY_VALUE;
			onTemp = EMPTY_VALUE;
		}
		else
		{
			/* Increment OFF_PERIOD */
			offTemp++;
		}
	}
}