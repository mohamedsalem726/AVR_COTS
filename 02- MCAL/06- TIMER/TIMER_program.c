/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  MCAL            *****************/
/****************   SWC:    TIMER           *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_register.h"
#include "TIMER_private.h"
#include "TIMER_config.h"

static void (*TIMER0_pvCallBackFunc)(void) = NULL;

void TIMER0_voidInit(void)
{
	/* Timer0 set mode */
#if TIMER0_MODE == PWM_PHASE_CORRECT
	CLR_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);
#elif TIMER0_MODE == CTC_MODE
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);

	/* Timer0 OC0 pin set mode */
	#if TIMER0_OC0_MODE == OC0_DISCONNECTED
		CLR_BIT(TCCR0,TCCR0_COM00);
		CLR_BIT(TCCR0,TCCR0_COM01);
	#elif TIMER0_OC0_MODE == OC0_TOGGLE
		SET_BIT(TCCR0,TCCR0_COM00);
		CLR_BIT(TCCR0,TCCR0_COM01);
	#elif TIMER0_OC0_MODE == OC0_CLEAR
		CLR_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
	#elif TIMER0_OC0_MODE == OC0_SET
		SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);
	#else
	#error
		"Wrong Timer0 OC0 pin mode configuration"
	#endif

		/* Timer0 interrupt Set */
	#if TIMER0_INTERRUPT == ENABLE
		SET_BIT(TIMSK,TIMSK_OCIE0);
	#elif TIMER0_INTERRUPT == DISABLE
		CLR_BIT(TIMSK,TIMSK_OCIE0);
	#else
	#error
		"Wrong Timer0 Interrupt configuration"
	#endif

		/* Set compare match value */
		OCR0 = TIMER0_COMPARE_VALUE;

#elif TIMER0_MODE == FAST_PWM
	SET_BIT(TCCR0,TCCR0_WGM01);
	SET_BIT(TCCR0,TCCR0_WGM00);
#else
#error
	"Wrong Timer0 mode configuration"
#endif

	/* Presacler Set */
#if TIMER0_PRESCALER == NO_PRESCALER
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_PRESCALER == DIV_BY_8
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_PRESCALER == DIV_BY_64
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_PRESCALER == DIV_BY_256
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#elif TIMER0_PRESCALER == DIV_BY_1024
	SET_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	SET_BIT(TCCR0,TCCR0_CS02);
#else
#error
	"Wrong Timer0 Prescaler configuration"
#endif

}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState = OK;

	if(Copy_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState = NULL_PIONTER;
	}

	return Local_u8ErrorState;
}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc != NULL)
	{
		TIMER0_pvCallBackFunc();
	}
	else
	{
		/* Do nothing */
	}
}
