/*
 * LED_Control_Project
 *
 *  Author: Mohamed Salah Abdelfatah
 */ 
 
#ifndef __DIO_H__
#define __DIO_H__

#include "stdint.h"

/******************* RCC Address *************************************************/
#define RCC_BASE										(0x400FE000)
#define RCGCGPIO_OFFSET 						(0x608)
#define RCC_GPIO										(*((volatile uint32_t*)(RCC_BASE + RCGCGPIO_OFFSET)))

/******************* Active PORT Address  ***************************************/
#define PORT_A_APB									(0x40004000)
#define PORT_B_APB									(0x40005000)
#define PORT_C_APB									(0x40006000)
#define PORT_D_APB									(0x40007000)
#define PORT_E_APB									(0x40024000)
#define PORT_F_APB									(0x40025000)
/********************************************************************************/

/********************************************************************************/
typedef struct
{
	volatile uint32_t PADDING_0[255];	/*0x000*/
	volatile uint32_t GPIODATA;				/*0x3FC*/
	volatile uint32_t GPIODIR; 				/*0x400*/
	volatile uint32_t GPIOIS;					/*0x404*/
	volatile uint32_t GPIOIBE;				/*0x408*/
	volatile uint32_t GPIOIEV;				/*0x40C*/
	volatile uint32_t GPIOIM;					/*0x410*/
	volatile uint32_t GPIORIS;				/*0x414*/
	volatile uint32_t GPIOMIS;				/*0x418*/
	volatile uint32_t GPIOICR;				/*0x41C*/
	volatile uint32_t GPIOAFSEL; 			/*0x420*/
	volatile uint32_t RESERVED_1[55];
	volatile uint32_t GPIODR2R; 			/*0x500*/
	volatile uint32_t GPIODR4R; 			/*0x504*/
	volatile uint32_t GPIODR8R; 			/*0x508*/
	volatile uint32_t GPIOODR; 				/*0x50C*/
	volatile uint32_t GPIOPUR; 				/*0x510*/
	volatile uint32_t GPIOPDR; 				/*0x514*/
	volatile uint32_t PADDING_2;                                   
	volatile uint32_t GPIODEN; 				/*0x51C*/
}tDio_Address;

/******************* Assign DIO Addresses ***************************************/
#define DIO_A_BASE									((tDio_Address*) PORT_A_APB)
#define DIO_B_BASE									((tDio_Address*) PORT_B_APB)
#define DIO_C_BASE									((tDio_Address*) PORT_C_APB)
#define DIO_D_BASE									((tDio_Address*) PORT_D_APB)
#define DIO_E_BASE									((tDio_Address*) PORT_E_APB)
#define DIO_F_BASE									((tDio_Address*) PORT_F_APB)
/********************************************************************************/

typedef enum
{
	CHANNEL_0,
	CHANNEL_1,
	CHANNEL_2,
	CHANNEL_3,
	CHANNEL_4,
	CHANNEL_5,
	CHANNEL_6,
	CHANNEL_7
}Dio_ChannelType;

typedef enum
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D,
	PORT_E,
	PORT_F
}Dio_PortType;

typedef enum
{
	LEVEL_LOW,
	LEVEL_HIGH
}Dio_LevelType;

typedef uint8_t Dio_PortLevelType;

/*
 * Function: Dio_ReadChannel
 * ----------------------------
 *	Read PORT PIN State
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param channelId: CHANNEL_0, CHANNEL_1, CHANNEL_2, CHANNEL_3, CHANNEL_4, CHANNEL_5, CHANNEL_6, CHANNEL_7
 *
 *	@return Dio_LevelType: 	LEVEL_LOW, LEVEL_HIGH
 */
Dio_LevelType Dio_ReadChannel(Dio_PortType PortId,Dio_ChannelType channelId);

/*
 * Function: Dio_WriteChannel
 * ----------------------------
 *	Set PORT PIN State
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param channelId: CHANNEL_0, CHANNEL_1, CHANNEL_2, CHANNEL_3, CHANNEL_4, CHANNEL_5, CHANNEL_6, CHANNEL_7
 *	@param level: LEVEL_LOW, LEVEL_HIGH
 *
 *	@return tGPIO_STATUS_x: GPIO_STATUS_SUCCESS, GPIO_STATUS_ERROR_PORT, GPIO_STATUS_ERROR_PIN, GPIO_STATUS_ERROR_DIR, GPIO_STATUS_ERROR_STATE
 */
void Dio_WriteChannel(Dio_PortType PortId, Dio_ChannelType channelId, Dio_LevelType level);

/*
 * Function: Dio_Read
 * ----------------------------
 *	Read PORT State
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *
 *	@return Dio_PortLevelType: 	0 .. 2^8
 */
Dio_PortLevelType Dio_Read(Dio_PortType PortId);

/*
 * Function: Dio_WritePort
 * ----------------------------
 *	Set PORT State
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param Dio_PortLevelType: 0 .. 2^8
 *
 *	@return void
*/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType level);

/*
 * Function: Dio_FlipChannel
 * ----------------------------
 *	Toggle PORT PIN State
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *	@param channelId: CHANNEL_0, CHANNEL_1, CHANNEL_2, CHANNEL_3, CHANNEL_4, CHANNEL_5, CHANNEL_6, CHANNEL_7
 *
 *	@return Dio_LevelType: LEVEL_LOW, LEVEL_HIGH
 */
Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_ChannelType ChannelId);

/*
 * Function: Dio_GetAddress
 * ----------------------------
 *	Get MCU Port Address
 *
 *	@param PortId: PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F
 *
 *	@return *tDio_Address
 */
tDio_Address* Dio_GetAddress(Dio_PortType portId);

#endif