/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  MCAL            *****************/
/****************   SWC:    EXTI            *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define EXTI_u8INT0    1
#define EXTI_u8INT1    2
#define EXTI_u8INT2    3
/**********************************************************/

/* Sense Options */
#define EXTI_u8LOWLEVEL      1
#define EXTI_u8ANYCHANGE     2
#define EXTI_u8FALLINGEDGE   3
#define EXTI_u8RISINGEDGE    4
/********************************************************/

/* Function pre build configuration */
void EXTI_voidInt0Init(void);

void EXTI_voidInt1Init(void);

void EXTI_voidInt2Init(void);
/**********************************************************/

/* Function post build configuration */
u8 EXTI_u8IntSetSenseControl(u8 Copy_u8Sense, u8 Copy_u8IntNumber);
/***********************************************************/

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void));

u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void));

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void));

#endif /* EXTI_INTERFACE_H_ */
