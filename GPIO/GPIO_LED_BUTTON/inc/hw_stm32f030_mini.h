
#ifndef __HW_STM32F030_MINI_H__
#define __HW_STM32F030_MINI_H__

#define write_reg(addr, value)    *((unsigned long int *)(addr)) = value
#define read_reg(addr, mask)      *((unsigned long int *)(addr)) & (mask)
/*		*/
/*	RCC_clock	*/
#define 		BASE_ADDR_RCC		0x40021000u
#define 		RCC_AHBENR			(BASE_ADDR_RCC + 0x14u)	

/*	GPIO - PC	*/
#define 		BASE_ADDR_GPIOC		0x48000800u
#define 		GPIOC_MODER			(BASE_ADDR_GPIOC + 0x00u)

#define 		GPIOC_MODER_IN		0x00u
#define 		GPIOC_MODER_OUT		0x01u
#define 		GPIOC_MODER_ALT		0x02u
#define 		GPIOC_MODER_ANALOG	0x03u

#define			GPIOC_ODR			(BASE_ADDR_GPIOC + 0x14u)
#define			GPIOC_BSRR			(BASE_ADDR_GPIOC + 0x18u)


/*	GPIO - PA	*/
#define 		BASE_ADDR_GPIOA		0x48000000u
#define 		GPIOA_MODER			(BASE_ADDR_GPIOA + 0x00u)
#define 		GPIOA_IDR			(BASE_ADDR_GPIOA + 0x10u)

/*	set_mode_led_pc9	*/
#define 		LED9		9

/*	set_mode_led_pc8	*/
#define 		LED8		8

/*	set_mode_button_pa0	*/
#define			BUTTON		0
#endif /* __HW_STM32F030_MINI_H__ */

