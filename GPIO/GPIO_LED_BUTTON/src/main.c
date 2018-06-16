
#include "hw_stm32f030_mini.h"
unsigned char co = 1;
void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

void enable_clock()
{
	unsigned long int tmp;
	tmp = read_reg(RCC_AHBENR,~(0x05u << 17));
	tmp = tmp | (0x05u << 17);
	write_reg(RCC_AHBENR,tmp);
}
void init_pin(void)
{
	unsigned long int tmp,tmp2;
	tmp = read_reg(GPIOC_MODER,~(0x05u << 16));
	tmp = tmp | (0x05u << 16);
	write_reg(GPIOC_MODER,tmp);
	
	//tmp2 = read_reg(GPIOA_MODER,~(GPIOC_MODER_IN));
	tmp2 = tmp2 | GPIOC_MODER_IN;
	write_reg(GPIOA_MODER,tmp2);
	
}
void LED_ON(unsigned char X)
{
	write_reg(GPIOC_BSRR, 1u << (X));
}
void LED_OFF(unsigned char X)
{
	write_reg(GPIOC_BSRR, 1u << (X + 16u));
}
void check_button()
{	
	unsigned long int tmp;
	tmp = read_reg(GPIOA_IDR,0x01u);
	if(tmp == 1)
	{
		if(co == 1)
		{
			LED_ON(LED9);
			LED_ON(LED8);
			co = 0;
		}
		else 
		{
			LED_OFF(LED9);
			LED_OFF(LED8);
			co = 1;
		}
	}
}

void main(void)
{
	enable_clock();
	init_pin();

  while(1)
  {
	check_button();
	delay(0x0f);
  }
}


void Reserved_IRQHandler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void NMI_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void HardFault_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SVC_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void PendSV_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}

void SysTick_Handler(void)
{
  while(1)
  {
    /* nothing to be run here */
  }
}


