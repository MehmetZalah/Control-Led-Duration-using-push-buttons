#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include "stdint.h"
#include "../DIO/DIO.h"
#include "../PORT/port.h"

typedef struct
{
	Dio_PortType PortNum;
	Port_Pin_x PortPin;
}Interrupt_ConfigType;

typedef struct
{
	volatile uint32_t NVIC_EN0;				/*0x100*/
	volatile uint32_t NVIC_EN1;				/*0x104*/
	volatile uint32_t NVIC_EN2;				/*0x108*/
	volatile uint32_t NVIC_EN3;				/*0x10C*/
	volatile uint32_t NVIC_EN4;				/*0x110*/
	volatile uint32_t PADDING[0x1CC];
	volatile uint32_t NVIC_PRI0[50];			/*0X400*/
}tNVIC_Address;

#define BASE_PERIPH									(0xE000E000)
#define NVIC_OFFSET                 (0x100)

#define NVIC_BASE_ADD										((tNVIC_Address* )(BASE_PERIPH + NVIC_OFFSET))

void INTERRRUPT_Init(const Interrupt_ConfigType* interrupt_ConfigType);
void INTERRRUPT_ClearFlag(Dio_PortType PortNum, Port_Pin_x PortPin);
#endif