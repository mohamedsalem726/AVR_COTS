/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  MCAL            *****************/
/****************   SWC:    EXTI            *****************/
/****************   Version:1.00            *****************/
/************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/* Options:
 *         1- EXTI_u8LOWLEVEL
 *         2- EXTI_u8ANYCHANGE
 *         3- EXTI_u8FALLINGEDGE
 *         4- EXTI_u8RISINGEDGE
 ***************************************************/
#define EXTI_INT0_SENSE       EXTI_u8FALLINGEDGE

/* Options:
 *         1- EXTI_u8LOWLEVEL
 *         2- EXTI_u8ANYCHANGE
 *         3- EXTI_u8FALLINGEDGE
 *         4- EXTI_u8RISINGEDGE
 ***************************************************/
#define EXTI_INT1_SENSE       EXTI_u8RISINGEDGE

/* Options:
 *         1- EXTI_u8FALLINGEDGE
 *         2- EXTI_u8RISINGEDGE
 ***************************************************/
#define EXTI_INT2_SENSE       EXTI_u8FALLINGEDGE
/************************************************************************/

/* Options:
 *         1- EXTI_ENABLED
 *         2- EXTI_DISABLED
 ***************************************************/
#define EXTI_INT0_INITIAL_STATE     EXTI_ENABLED

/* Options:
 *         1- EXTI_ENABLED
 *         2- EXTI_DISABLED
 ***************************************************/
#define EXTI_INT1_INITIAL_STATE     EXTI_ENABLED

/* Options:
 *         1- EXTI_ENABLED
 *         2- EXTI_DISABLED
 ***************************************************/
#define EXTI_INT2_INITIAL_STATE     EXTI_ENABLED
/**************************************************************************/

#endif /* EXTI_CONFIG_H_ */
