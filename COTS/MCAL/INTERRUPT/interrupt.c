#include "interrupt.h"
#include "../Utilities.h"

void INTERRRUPT_Init(const Interrupt_ConfigType* interrupt_ConfigType)
{	
    /* edge-sensitive */
		CLEAR_BIT(Dio_GetAddress(interrupt_ConfigType->PortNum)->GPIOIS,interrupt_ConfigType->PortPin);
    
		/* Interrupt generation is controlled by the GPIO Interrupt Event (GPIOIEV) not both */
		CLEAR_BIT(Dio_GetAddress(interrupt_ConfigType->PortNum)->GPIOIBE,interrupt_ConfigType->PortPin);
    		
		/* falling edge trigger */
		CLEAR_BIT(Dio_GetAddress(interrupt_ConfigType->PortNum)->GPIOIEV,interrupt_ConfigType->PortPin);
		
		/* clear any prior interrupt */
		SET_BIT(Dio_GetAddress(interrupt_ConfigType->PortNum)->GPIOICR,interrupt_ConfigType->PortPin);
		
		/* unmask interrupt */
		SET_BIT(Dio_GetAddress(interrupt_ConfigType->PortNum)->GPIOIM,interrupt_ConfigType->PortPin);
	
		switch(interrupt_ConfigType->PortNum)
		{
			case PORT_F:
			/* priority 3 */
			NVIC_BASE_ADD->NVIC_PRI0[30] = (3<<5);
			
			/* enable */
			NVIC_BASE_ADD->NVIC_EN0 |= (1<<30);	 //GPIOF_HANDLER
			break;
		}
}

void INTERRRUPT_ClearFlag(Dio_PortType PortNum, Port_Pin_x PortPin)
{
	SET_BIT(Dio_GetAddress(PortNum)->GPIOICR,PortPin);
}