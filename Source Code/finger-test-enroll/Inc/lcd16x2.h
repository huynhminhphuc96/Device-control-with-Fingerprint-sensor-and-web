#include "main.h"
#include "stm32f1xx_hal.h"

#define LCD16X2_PORT	GPIOB
#define __RCC_LCD16X2_PORT_ENABLE() __HAL_RCC_GPIOB_CLK_ENABLE()
#define LCD16X2_D4    GPIO_PIN_6
#define LCD16X2_D5    GPIO_PIN_7
#define LCD16X2_D6    GPIO_PIN_8
#define LCD16X2_D7    GPIO_PIN_9
#define	LCD16X2_RS    GPIO_PIN_4
#define	LCD16X2_EN    GPIO_PIN_5

//LCD funtions
#define LCD_FUNCTION_SET       0X28 // giao thuc 4 bit
#define LCD_DISPLAY_CONTROL    0X0C // cho phep hien thi man hinh
#define LCD_CLEAR_DISPLAY      0X01 // xoa toan bo khung hinh
#define LCD_ENTRY_MODE         0X06 // tang ID, khong dich khung hinh

#define LCD_ADDR_LINE1         0X80
#define LCD_ADDR_LINE2         0XC0

void LCD16X2_Config(void);

/*------------------------------------------------------------------------------
Noi Dung    :   Gui tin hieu Enable den LCD16X2.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
 -------------------------------------------------------------------------------*/
 
void LCD16X2_Enable(void);
void LCD16X2_Send4Bit(unsigned char Data);
void LCD16X2_SendCommand(unsigned char Command);
void LCD16X2_Init(void);
void LCD16X2_Gotoxy(unsigned char x,unsigned char y);
void LCD16X2_Clear(void);
void LCD16X2_PutChar(unsigned char Data);
void LCD16X2_Puts(unsigned char *s);
void LCD16X2_Fingerprint(unsigned char *s);



