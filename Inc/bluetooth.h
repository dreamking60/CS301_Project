#ifndef __BLUE_TOOTH__
#define __BLUE_TOOTH__

#include "stm32f1xx_hal.h"
#include "stdlib.h"
#include "sys.h"
#include "lcd.h"

u8 Bluetooth_Init(void);
void HC05_CFG_CMD(u8 *str);
u8 HC05_Get_Role(void);
u8 HC05_Set_Cmd(u8* atstr);
void HC_05_SET_NAME(char *astr);
void HC05_Sta_Show(u8 uartsta);
void HC05_Role_Show(void);
#define HC05_KEY  	PAout(1)
#define HC05_LED  	PAin(4)

#endif
