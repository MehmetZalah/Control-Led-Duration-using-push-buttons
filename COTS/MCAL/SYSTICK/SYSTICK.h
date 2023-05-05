/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 

#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "stdint.h"

#define SYSCLK						(16000000)
#define SYSTICK_MS				(SYSCLK / 1000)

#define SYSTICK_BASE										(0xE000E000)
#define SYSTICK_STCTRL_REG_OFFSET				(0x010)
#define SYSTICK_STCTRL_COUNT_BIT				(16)
#define SYSTICK_STCTRL_CLKSRC_BIT				(2)
#define SYSTICK_STCTRL_INTEN_BIT				(1)
#define SYSTICK_STCTRL_ENABLE_BIT				(0)

#define SYSTICK_STRELOAD_REG_OFSET			(0x014)
#define SYSTICK_STCURRENT_REG_OFFSET		(0x018)

typedef struct
{
	volatile uint32_t STCTRL;
	volatile uint32_t STRELOAD;
	volatile uint32_t STCURRENT;
}tSystick_Address;

#define SYSTICK									((tSystick_Address*)(SYSTICK_BASE + SYSTICK_STCTRL_REG_OFFSET))

typedef void(*cbType)(void);

/*
 * Function: SYSTICK_cb_register
 * ----------------------------
 *	SYSTICK CallBack Registraion
 *	@param cbType: function ptr
 *	@return void
 */
void SYSTICK_cb_register(cbType ptr);

/*
 * Function: SYSTICK_Wait
 * ----------------------------
 *	Wait in milli Seconds
 *
 *	@param uint32_t timeMS
 *
 *	@return void
 */
void SYSTICK_Wait(uint32_t timeMS);



#endif