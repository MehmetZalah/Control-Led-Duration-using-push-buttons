#ifndef __USER_H__
#define __USER_H__


/*
 * Function: USER_Init
 * ----------------------------
 *	USER Module Initialization Function
 *
 *		@return void
 */
void USER_Init(void);


/*
 * Function: USER_Handler
 * ----------------------------
 *	interrupt handler function for PORT F
 *
 *		@return void
 */
void USER_Handler(void);

#endif