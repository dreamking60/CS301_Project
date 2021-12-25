#include <bluetooth.h>
#include "delay.h"
#include "sys.h"
#include "string.h"
#include "tim.h"
#include "usart.h"
#include "math.h"
#include "stdio.h"
#include "main.h"
#include "gpio.h"
u8 Bluetooth_Init(void)
{
	u8 retry=10,t;
	u8 temp=1;

	GPIO_InitTypeDef GPIO_Initure;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

    GPIO_Initure.Pin=GPIO_PIN_4;
    GPIO_Initure.Mode=GPIO_MODE_INPUT;
    GPIO_Initure.Pull=GPIO_PULLUP;
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);

    GPIO_Initure.Pin=GPIO_PIN_1;
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;
    GPIO_Initure.Pull=GPIO_PULLDOWN;
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);

    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
    delay_ms(10);
    HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
	USART2_Init(9600);

	if(retry==0) temp=1;
	return temp;
}

u8 HC05_Set_Cmd(u8* atstr)
{
	u8 retry=0X0F;
	u8 temp,t;
	while(retry--)
	{
		HC05_KEY=1;
		delay_ms(20);
		u2_printf("%s\r\n",atstr);
		HC05_KEY=0;
		for(t=0;t<20;t++)
		{
			if(USART2_RX_STA&0X8000)break;
			delay_ms(5);
		}
		if(USART2_RX_STA&0X8000)
		{
			temp=USART2_RX_STA&0X7FFF;
			USART2_RX_STA=0;
			if(temp==4&&USART2_RX_BUF[0]=='O')
			{
				temp=0;
				break;
			}
		}
	}
	if(retry==0)temp=0XFF;
	return temp;
}
u8 HC05_Get_Role(void)
{
	u8 retry=0X0F;
	u8 temp,t;
	while(retry--)
	{
		HC05_KEY=1;
		delay_ms(10);
		u2_printf("AT+ROLE?\r\n");
		for(t=0;t<20;t++)
		{
			delay_ms(10);
			if(USART2_RX_STA&0X8000)break;
		}
		HC05_KEY=0;
		if(USART2_RX_STA&0X8000)
		{
			temp=USART2_RX_STA&0X7FFF;
			USART2_RX_STA=0;
			if(temp==13&&USART2_RX_BUF[0]=='+')
			{
				temp=USART2_RX_BUF[6]-'0';
				break;
			}
		}
	}
	if(retry==0)temp=0XFF;
	return temp;
}
void HC05_CFG_CMD(u8 *str)
{
	u8 temp;
	u8 t;
	HC05_KEY=1;
	delay_ms(10);
	u2_printf("%s\r\n",(char*)str);
	for(t=0;t<50;t++)
	{
		if(USART2_RX_STA&0X8000)break;
		delay_ms(10);
	}
	HC05_KEY=0;
	if(USART2_RX_STA&0X8000)
	{
		temp=USART2_RX_STA&0X7FFF;
		USART2_RX_STA=0;
		USART2_RX_BUF[temp]=0;
		printf("\r\n%s",USART2_RX_BUF);
	}
}
void HC_05_SET_NAME(char *astr)
{
	  u8 temp;
		u8 t;
	HC05_KEY=1;
	u2_printf("AT+NAME=%s\r\n",astr);
	for(t=0;t<50;t++)
	{
		if(USART2_RX_STA&0X8000)break;
		delay_ms(10);
	}
	HC05_KEY=0;
}

void HC05_Role_Show(void)
{
	u16 POINT=POINT_COLOR;
	static u8 Role_Sta=0;
    POINT_COLOR=BLUE;
	if(HC05_Get_Role()==1)
	{if(Role_Sta!=1)
	{
		Role_Sta=1;
     LCD_ShowString(10,20,200,24,16,"ROLE: master");
	}
	}else
	{
		Role_Sta=0;
	    LCD_ShowString(10,20,200,24,16,"ROLE: slave");
	}
	POINT_COLOR=POINT;
}
void HC05_Sta_Show(u8 uartsta)
{
	u16 POINT=POINT_COLOR;

    static u8 HC05_STA=2;
	if(HC05_LED&&(uartsta==open))
	{
		if(HC05_STA!=1)
		{
			POINT_COLOR=BLUE;
			HC05_STA=1;
			   LCD_Fill(110,20,230,42,WHITE);
			   LED0_Value = 1;
			   LED1_Value = 0;
			 LCD_ShowString(120,20,120,16,16,"STA:Connected");
			printf("STA:Connected\r\n");

		}
	}
	else
	{
		if(HC05_STA!=0)
		{
			POINT_COLOR=RED;
			HC05_STA=0;
			   LED0_Value = 0;
			   LED1_Value = 1;
			 LCD_ShowString(120,20,120,16,16,"STA:Disconnect");
			 printf("STA:Disconnect\r\n");
		}
	}
	POINT_COLOR=POINT;
}
