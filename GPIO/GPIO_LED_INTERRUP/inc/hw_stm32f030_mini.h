
#ifndef __HW_STM32F030_MINI_H__
#define __HW_STM32F030_MINI_H__

#define write_reg(addr, value)    *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      *((unsigned long int *)(addr)) & (mask)
/*		*/
/*	RCC_clock	*/
#define			BASE_ADDR_RCC		0x40021000u
#define			RCC_AHBENR			(BASE_ADDR_RCC + 0x14u)

/*	GPIO	*/
#define 		BASE_ADDR_GPIOC		0x48000800u
#define 		GPIOC_MODER			(BASE_ADDR_GPIOC + 0x00u)
#define			GPIOC_ODR			(BASE_ADDR_GPIOC + 0x14u)
#define			GPIOC_BSRR			(BASE_ADDR_GPIOC + 0x18u)

#define			BASE_ADDR_GPIOA		0x48000000u
#define			GPIOA_MODER			(BASE_ADDR_GPIOA + 0x00u)
#define			GPIOA_IDR			(BASE_ADDR_GPIOA + 0x10u)

#define 		GPIO_MODER_INPUT	0x00u
#define 		GPIO_MODER_OUTPUT	0x01u
#define 		GPIO_MODER_ATLPUT	0x02u
#define 		GPIO_MODER_ANALOG	0x03u

/*EXTI*/
#define			BASE_ADDR_EXTI		0x40010400u
#define			EXTI0_IMR			(BASE_ADDR_EXTI + 0x00u)
#define			EXTI0_RTSR			(BASE_ADDR_EXTI + 0x08u)
#define			EXTI0_PR			(BASE_ADDR_EXTI + 0x14u)
/*SYSCFGCR1*/
#define			BASE_ADDR_SYSCFG	0x40010000u
#define			SYSCFG_EXTICR1		(BASE_ADDR_SYSCFG + 0x08u)

/* NVIC */
#define NVIC_ISER			0xE000E100u
#define NVIC_ICER			0xE000E180u
#define NVIC_ISPR			0xE000E200u
#define NVIC_ICPR			0xE000E280u
#define NVIC_PRI1			0xE000E404u

/*set LED*/
#define			LED8		8
#define			LED9		9
/*	set button	*/
#define			BUTTON		0

#endif /* __HW_STM32F030_MINI_H__ */

