/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  MCAL            *****************/
/****************   SWC:    PORT            *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#include "STD_TYPES.h"

#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_interface.h"
#include "PORT_register.h"

void PORT_voidInit(void)
{
	DDRA  = PORTA_DIRECTION;
	DDRB  = PORTB_DIRECTION;
	DDRC  = PORTC_DIRECTION;
	DDRD  = PORTD_DIRECTION;

	PORTA = PORTA_INITIAL_VALUE;
	PORTB = PORTB_INITIAL_VALUE;
	PORTC = PORTC_INITIAL_VALUE;
	PORTD = PORTD_INITIAL_VALUE;
}


