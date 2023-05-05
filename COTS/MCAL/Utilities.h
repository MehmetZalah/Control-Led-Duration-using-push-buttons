#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#define SET_BIT(PORT,PORTPIN)						( (PORT) |= (1<<PORTPIN) )
#define READ_BIT(PORT,PORTPIN)					(	((PORT)>>(PORTPIN))	&1 )
#define CLEAR_BIT(PORT,PORTPIN)					(	(PORT) &=~(1<<PORTPIN) )
#define TOGGLE_BIT(PORT,PORTPIN)				(	(PORT) ^= (1<<PORTPIN) )

#endif