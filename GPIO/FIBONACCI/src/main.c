
#include "hw_stm32f030_mini.h"
unsigned char co;
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

//------------------------------------------------------------------------------------------//


void LED_ON(unsigned char X)
{
	write_reg(GPIOC_BSRR,1u << X);
}
void LED_OFF(unsigned char X)
{
	write_reg(GPIOC_BSRR,1u << (X + 16u));
}

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
void enable_clock(void)
{
	unsigned long int tmp;
	tmp = read_reg(RCC_AHBENR,~(0x05u << 17));
	tmp = tmp | (0x05u << 17);
	write_reg(RCC_AHBENR,tmp);
}
void init_GPIOC(void)
{
	unsigned long int tmp;
	tmp = read_reg(GPIOC_MODER,~(0x05u << 16));
	tmp = tmp | (GPIO_MODER_OUTPUT << 18);
	tmp = tmp | (GPIO_MODER_OUTPUT << 16);
	write_reg(GPIOC_MODER,tmp);
	
	tmp = read_reg(GPIOA_MODER,~(0x00u << 0));
	tmp = tmp | (GPIO_MODER_INPUT << 0);
	write_reg(GPIOA_MODER,tmp);
	
	
}
void init_interrup(void)
{
	unsigned long int tmp;
	/*enable interrup EXTI0*/
	tmp = read_reg(EXTI0_IMR,~(1u << 0));
	tmp = tmp | (1 << 0);
	write_reg(EXTI0_IMR,tmp);
	
	tmp = read_reg(EXTI0_RTSR,~(1u << 0));
	tmp = tmp | (1 << 0);
	write_reg(EXTI0_RTSR,tmp);
	
	/*SYSCFG*/	
	tmp = read_reg(SYSCFG_EXTICR1, ~(0x0F << 0));
	tmp = tmp | (0x00 << 0);
	write_reg(SYSCFG_EXTICR1, tmp);
	
	/*NVIC*/
	tmp = read_reg(NVIC_PRI1,~(0xFF << 8));
	tmp = tmp | (1u << 14);
	write_reg(NVIC_PRI1,tmp);
	
	tmp = read_reg(NVIC_ISER,~(1u << 5));
	tmp = tmp | (1 << 5);
	write_reg(NVIC_ISER,tmp);
	/* enable global interrupt */
	asm("cpsie i");
}
void EXTI0_1_IRQHandler()
{
	/*		*/
	unsigned long int tmp;
	tmp = read_reg(EXTI0_PR ,(1 << 0));
	if(tmp == 1)
	{
		co = 1;
	}
	/* xoa co ngat */
	tmp = 1 << 0;
	write_reg(EXTI0_PR, tmp);
	write_reg(NVIC_ICPR, (1 << 5));
	
}
int Fibonacci(unsigned long int n)
{
	if(n <= 2) return 1;
	return (Fibonacci(n - 1) + Fibonacci(n - 2));
}
void main(void)
{
	enable_clock();
	init_GPIOC();
	init_interrup();
	co = 0;
	unsigned long int n = 1,i;
  while(1)
  {
	LED_ON(LED8);
	delay(0x0f);
	LED_OFF(LED8);
	delay(0x0f);
		switch (co) 
		{
			case 0:
			{
				for(i = 1; i <= Fibonacci(n); i++)
				{
					LED_ON(LED9);
					delay(50);
					LED_OFF(LED9);
					delay(50);
				}
				n ++;
			}
			case 1:
			{
				for(i = 1; i <= Fibonacci(n - 1); i++)
				{
					LED_ON(LED9);
					delay(50);
					LED_OFF(LED9);
					delay(50);
				}
				break;
			}
		
		}
	/*
			if(co == 0)
	{
		for(i = 1; i <= Fibonacci(n); i++)
		{
			LED_ON(LED9);
			delay(50);
			LED_OFF(LED9);
			delay(50);
		}
		n ++;
	}
	else
	{
		for(i = 1; i <= Fibonacci(n - 1); i++)
			{
				LED_ON(LED9);
				delay(50);
				LED_OFF(LED9);
				delay(50);
			}
	}
	delay(300);
	*/
	
  }
}








