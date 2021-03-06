#ifndef __LCD_H
#define __LCD_H		
#include "stm32f1xx_hal.h"
#include "stdlib.h"
#include "sys.h"
//LCD
typedef struct  
{										    
	u16 width;
	u16 height;
	u16 id;
	u8  dir;
	u16	wramcmd;
	u16 setxcmd;
	u16  setycmd;
}_lcd_dev; 	  


extern _lcd_dev lcddev;

extern u16  POINT_COLOR;
extern u16  BACK_COLOR;
extern const unsigned char gImage_user[4616];
extern void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p);
extern const unsigned char gImage_slave[4616] ;
////////////////////////////////////////////////////////////////////
//-----------------LCD----------------
#define	LCD_LED PCout(10) 				//PC10
 
#define	LCD_CS_SET  GPIOC->BSRR=1<<9    //PC9
#define	LCD_RS_SET	GPIOC->BSRR=1<<8    //PC8
#define	LCD_WR_SET	GPIOC->BSRR=1<<7    //PC7
#define	LCD_RD_SET	GPIOC->BSRR=1<<6    //PC6
								    
#define	LCD_CS_CLR  GPIOC->BRR=1<<9     //PC9
#define	LCD_RS_CLR	GPIOC->BRR=1<<8     //PC8
#define	LCD_WR_CLR	GPIOC->BRR=1<<7     //PC7
#define	LCD_RD_CLR	GPIOC->BRR=1<<6     //PC6


//PB0~15
#define DATAOUT(x) GPIOB->ODR=x;
#define DATAIN     GPIOB->IDR;

 
//////////////////////////////////////////////////////////////////////
#define L2R_U2D  0
#define L2R_D2U  1
#define R2L_U2D  2
#define R2L_D2U  3

#define U2D_L2R  4
#define U2D_R2L  5
#define D2U_L2R  6
#define D2U_R2L  7

#define DFT_SCAN_DIR  L2R_U2D
	 
#define L2R_U2D  0
#define L2R_D2U  1
#define R2L_U2D  2
#define R2L_D2U  3

#define U2D_L2R  4
#define U2D_R2L  5
#define D2U_L2R  6
#define D2U_R2L  7

#define DFT_SCAN_DIR  L2R_U2D

#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40
#define BRRED 			 0XFC07
#define GRAY  			 0X8430
//GUI

#define DARKBLUE      	 0X01CF
#define LIGHTBLUE      	 0X7D7C
#define GRAYBLUE       	 0X5458
 
#define LIGHTGREEN     	 0X841F
#define LGRAY 			 0XC618

#define LGRAYBLUE        0XA651
#define LBBLUE           0X2B12
	    															  
void LCD_Init(void);
void LCD_DisplayOn(void);
void LCD_DisplayOff(void);
void LCD_Clear(u16 Color);
void LCD_SetCursor(u16 Xpos, u16 Ypos);
void LCD_DrawPoint(u16 x,u16 y);
void LCD_Fast_DrawPoint(u16 x,u16 y,u16 color);
u16  LCD_ReadPoint(u16 x,u16 y);
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r);
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2);
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color);
void LCD_Color_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 *color);
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode);
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size);
void LCD_ShowxNum(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode);
void LCD_ShowString(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p);

void LCD_WriteReg(u16 LCD_Reg, u16 LCD_RegValue);
u16 LCD_ReadReg(u16 LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(u16 RGB_Code);		  
void LCD_Scan_Dir(u8 dir);
void LCD_Display_Dir(u8 dir);
void LCD_Set_Window(u16 sx,u16 sy,u16 width,u16 height);

#define LCD_WR_DATA(data){\
LCD_RS_SET;\
LCD_CS_CLR;\
DATAOUT(data);\
LCD_WR_CLR;\
LCD_WR_SET;\
LCD_CS_SET;\
} 

#define SSD_HOR_RESOLUTION		800
#define SSD_VER_RESOLUTION		480

#define SSD_HOR_PULSE_WIDTH		1
#define SSD_HOR_BACK_PORCH		46
#define SSD_HOR_FRONT_PORCH		210

#define SSD_VER_PULSE_WIDTH		1
#define SSD_VER_BACK_PORCH		23
#define SSD_VER_FRONT_PORCH		22

#define SSD_HT	(SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS	(SSD_HOR_BACK_PORCH)
#define SSD_VT 	(SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)
						  		 
#endif













