/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  MCAL            *****************/
/****************   SWC:    EXTI            *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_register.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

/* Global pionter to function to hold INT ISR address */
void (*EXTI_pvInt0Func)(void) = NULL;
void (*EXTI_pvInt1Func)(void) = NULL;
void (*EXTI_pvInt2Func)(void) = NULL;

void EXTI_voidInt0Init(void)
{
	/* Set sense control for INT0 */
#if EXTI_INT0_SENSE == EXTI_u8LOWLEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_INT0_SENSE == EXTI_u8ANYCHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_INT0_SENSE == EXTI_u8FALLINGEDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif EXTI_INT0_SENSE == EXTI_u8RISINGEDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "Please Choose the Correct sense for INT0"
#endif

	/* Peripheral interrupt enable for INT0 */
#if EXTI_INT0_INITIAL_STATE == EXTI_ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif EXTI_INT0_INITIAL_STATE == EXTI_DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong EXTI_INT0_INITIAL_STATE configuration"
#endif
}

void EXTI_voidInt1Init(void)
{
	/* Set sense control for INT1 */
#if EXTI_INT1_SENSE == EXTI_u8LOWLEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_INT1_SENSE == EXTI_u8ANYCHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_INT1_SENSE == EXTI_u8FALLINGEDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif EXTI_INT1_SENSE == EXTI_u8RISINGEDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "Please Choose the Correct sense for INT1"
#endif

	/* Peripheral interrupt enable for INT0 */
#if EXTI_INT1_INITIAL_STATE == EXTI_ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif EXTI_INT1_INITIAL_STATE == EXTI_DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong EXTI_INT1_INITIAL_STATE configuration"
#endif
}

void EXTI_voidInt2Init(void)
{
	/* Set sense control for INT1 */
#if EXTI_INT2_SENSE == EXTI_u8FALLINGEDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
#elif EXTI_INT2_SENSE == EXTI_u8RISINGEDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
#error "Please Choose the Correct sense for INT2"
#endif

	/* Peripheral interrupt enable for INT0 */
#if EXTI_INT2_INITIAL_STATE == EXTI_ENABLED
	SET_BIT(GICR,GICR_INT2);
#elif EXTI_INT2_INITIAL_STATE == EXTI_DISABLED
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong EXTI_INT2_INITIAL_STATE configuration"
#endif
}

u8 EXTI_u8IntSetSenseControl(u8 Copy_u8Sense, u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8IntNumber)
	{
	case EXTI_u8INT0:
		switch(Copy_u8Sense)
		{
		case EXTI_u8LOWLEVEL: CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
		case EXTI_u8ANYCHANGE: SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
		case EXTI_u8FALLINGEDGE: CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
		case EXTI_u8RISINGEDGE: SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
		default: Local_u8ErrorState = NOK; break;
		}
		break;
		case EXTI_u8INT1:
			switch(Copy_u8Sense)
			{
			case EXTI_u8LOWLEVEL: CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
			case EXTI_u8ANYCHANGE: SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
			case EXTI_u8FALLINGEDGE: CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
			case EXTI_u8RISINGEDGE: SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
			default: Local_u8ErrorState = NOK; break;
			}
			break;
			case EXTI_u8INT2:
				switch(Copy_u8Sense)
				{
				case EXTI_u8FALLINGEDGE: SET_BIT(MCUCSR,MCUCSR_ISC2); break;
				case EXTI_u8RISINGEDGE: CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
				default: Local_u8ErrorState = NOK; break;
				}
				break;
				default:
					Local_u8ErrorState = NOK;
					break;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8IntNumber)
	{
	case EXTI_u8INT0: SET_BIT(GICR,GICR_INT0); break;
	case EXTI_u8INT1: SET_BIT(GICR,GICR_INT1); break;
	case EXTI_u8INT2: SET_BIT(GICR,GICR_INT2); break;
	default: Local_u8ErrorState = NOK;         break;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8IntDisable(u8 Copy_u8IntNumber)
{
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8IntNumber)
	{
	case EXTI_u8INT0: CLR_BIT(GICR,GICR_INT0); break;
	case EXTI_u8INT1: CLR_BIT(GICR,GICR_INT1); break;
	case EXTI_u8INT2: CLR_BIT(GICR,GICR_INT2); break;
	default: Local_u8ErrorState = NOK;         break;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState = OK;

	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState = NULL_PIONTER;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState = OK;

	if(Copy_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func = Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorState = NULL_PIONTER;
	}

	return Local_u8ErrorState;
}

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState = OK;

	if(Copy_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func = Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorState = NULL_PIONTER;
	}

	return Local_u8ErrorState;
}

/* ISR of INT0 */
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/* Do nothing */
	}

}

/* ISR of INT1 */
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func();
	}
	else
	{
		/* Do nothing */
	}
}

/* ISR of INT2 */
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func();
	}
	else
	{
		/* Do nothing */
	}
}
