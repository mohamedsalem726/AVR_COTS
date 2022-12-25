/************************************************************/
/************************************************************/
/****************   Author: Mohamed Salem   *****************/
/****************   Layer:  HAL             *****************/
/****************   SWC:    SSD             *****************/
/****************   Version:1.00            *****************/
/************************************************************/
/************************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

typedef struct
{
	u8 SSD_Port;
	u8 SSD_EnablePort;
	u8 SSD_EnablePin;
	u8 SSD_Type;
}SSD_t;

#define COM_ANODE      0
#define COM_CATHOD     1

u8 SDD_u8SetNumber(u8 Copy_u8Number, SSD_t *Copy_pSSD);

u8 SSD_voidEnable(SSD_t *Copy_pSSD);

u8 SSD_voidDisable(SSD_t *Copy_pSSD);



#endif /* SSD_INTERFACE_H_ */
