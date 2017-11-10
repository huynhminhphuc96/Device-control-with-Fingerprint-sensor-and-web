/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "systemConfig.h"
#include "R305.h"
#include "lcd16x2.h"

void delay_ms(uint32_t delay)
{
	while(delay--)
	{
		HAL_Delay(1000);
	}
}
/* Main function -------------------------------------------------------------*/
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  GPIO_Init();
  UART1_FINGER_Init();
	LCD16X2_Config();
	LCD16X2_Init();
	
	uint8_t i,y;
	LCD16X2_Fingerprint("Empty Database.");
	HAL_Delay(500);
	if(!emptyDatabase()){
		LCD16X2_Fingerprint("Done.");
		HAL_Delay(1000);
	}
	LCD16X2_Fingerprint("Enroll finger...");
	HAL_Delay(1000);
	if(verifyPassword()){
		for(i =0; i<2; i++){
			while(!fingerEnroll(i)){
				HAL_Delay(2000);
			}
			HAL_Delay(2000);
		}
	}
	/* Infinite loop */
	LCD16X2_Fingerprint("Find finger...");
	HAL_Delay(1000);
	while (1)
	{
			y=fingerIDSearch();
			if(y == 0 || y == 1 )
			{
				HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);			
			}
			HAL_Delay(1000);
	}
}


