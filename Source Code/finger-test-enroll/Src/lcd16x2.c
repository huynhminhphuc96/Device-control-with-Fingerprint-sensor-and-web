
#include "lcd16x2.h"

void LCD16X2_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __RCC_LCD16X2_PORT_ENABLE();

	HAL_GPIO_WritePin(LCD16X2_PORT, LCD16X2_EN|LCD16X2_RS|
																	LCD16X2_D4|LCD16X2_D5|LCD16X2_D6|LCD16X2_D7,GPIO_PIN_SET);

  /*Configure LCD16X2 DATA : PB4 | PB5 | PB6 | PB7 | PB8 | PB9 */
  GPIO_InitStruct.Pin = LCD16X2_D4|LCD16X2_D5|LCD16X2_D6|LCD16X2_D7|LCD16X2_EN|LCD16X2_RS;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCD16X2_PORT, &GPIO_InitStruct);


}

void LCD16X2_Fingerprint(unsigned char *s)
{
	LCD16X2_Clear();
	LCD16X2_Gotoxy(0,0);
	LCD16X2_Puts(s);
}

/*------------------------------------------------------------------------------
Noi Dung    :   Gui tin hieu Enable den LCD16X2.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
 -------------------------------------------------------------------------------*/

void LCD16X2_Enable(void)
{
	HAL_GPIO_WritePin(LCD16X2_PORT, LCD16X2_EN, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD16X2_PORT, LCD16X2_EN, GPIO_PIN_RESET);
	HAL_Delay(1); 
}

/*------------------------------------------------------------------------------
Noi Dung    :   Gui 4 bit du lieu den LCD16X2.
Tham Bien   :   Data: 4 bit thap cua Data chua 4 bit du lieu can gui.
Tra Ve      :   Khong.
 -------------------------------------------------------------------------------*/

void LCD16X2_Send4Bit(unsigned char Data)
{
	HAL_GPIO_WritePin(LCD16X2_PORT, LCD16X2_D4, (Data&0x1)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD16X2_PORT, LCD16X2_D5,	((Data>>1)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD16X2_PORT, LCD16X2_D6,	((Data>>2)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCD16X2_PORT, LCD16X2_D7,	((Data>>3)&0x01)?GPIO_PIN_SET:GPIO_PIN_RESET);
	
}

/*------------------------------------------------------------------------------
Noi Dung    :   Gui 1 byte du lieu den LCD16X2.
Tham Bien   :   command: lenh can ghi
Tra Ve      :   Khong.
vi du       :   LCD16X2_SendCommand (0x01);
 -------------------------------------------------------------------------------*/

void LCD16X2_SendCommand(unsigned char Command)
{
	LCD16X2_Send4Bit(Command>>4);   /* Gui 4 bit cao */
	LCD16X2_Enable() ;
	LCD16X2_Send4Bit(Command);      /* Gui 4 bit thap*/
	LCD16X2_Enable() ;
}

/*------------------------------------------------------------------------------
Noi Dung    :   Khoi tao LCD16X2.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
 -------------------------------------------------------------------------------*/
 
void LCD16X2_Init(void)
{
	LCD16X2_Send4Bit(0x00);
	HAL_GPIO_WritePin(LCD16X2_PORT,LCD16X2_RS,GPIO_PIN_RESET);
	LCD16X2_Send4Bit(0x03);
	LCD16X2_Enable();
	LCD16X2_Enable();
	LCD16X2_Enable();
	LCD16X2_Send4Bit(0x02);
	LCD16X2_Enable();
	LCD16X2_SendCommand(0x28); // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
	LCD16X2_SendCommand(0x0C); // cho phep hien thi man hinh
	LCD16X2_SendCommand(0x06); // tang ID, khong dich khung hinh
	LCD16X2_SendCommand(0x01); // xoa toan bo khung hinh
}

/*------------------------------------------------------------------------------
Noi Dung    :   Thiet lap vi tri con tro LCD16X2.
Tham Bien   :   x: vi tri cot cua con tro. x = 0 - 15.
                y: vi tri hang cua con tro. y= 0,1.
Tra Ve      :   Khong.
Vi du       :   LCD16X2_Gotoxy(0,0);
 -------------------------------------------------------------------------------*/
 
void LCD16X2_Gotoxy(unsigned char  x, unsigned char  y)
{
	unsigned char  address;
	if(!y)
		address = (0x80+x);
	else
		address = (0xC0+x);
	HAL_Delay(1);
	LCD16X2_SendCommand(address);
	HAL_Delay(1);
}

/*------------------------------------------------------------------------------
Noi Dung    :   Xoa noi dung hien thi tren LCD16X2.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
 -------------------------------------------------------------------------------*/
 
void LCD16X2_Clear(void)
{
	LCD16X2_SendCommand(0x01);  
	HAL_Delay(1);
}

/*------------------------------------------------------------------------------
Noi Dung    :   Viet 1 ki tu len LCD16X2.
Tham Bien   :   Data  :   Gia tri ki tu can hien thi.
Tra Ve      :   Khong.
 -------------------------------------------------------------------------------*/
void LCD16X2_PutChar(unsigned char Data)
{
	HAL_GPIO_WritePin(LCD16X2_PORT, LCD16X2_RS, GPIO_PIN_SET);
	LCD16X2_SendCommand( Data );
	HAL_GPIO_WritePin(LCD16X2_PORT, LCD16X2_RS, GPIO_PIN_RESET);
}

/*------------------------------------------------------------------------------
Noi Dung    :   Viet 1 chuoi ki tu len LCD16X2.
Tham Bien   :   *s    :   chuoi du lieu can hien thi.
Tra Ve      :   Khong.
 -------------------------------------------------------------------------------*/
void LCD16X2_Puts(unsigned char *s)
{
	while (*s)
	{
		LCD16X2_PutChar(*s);
		s++;
	}
}




