/*
 * Copyright (c) 2018 Linaro Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <drivers/pinmux.h>
#include <sys/sys_io.h>

#include <pinmux/stm32/pinmux_stm32.h>

/* pin assignments for NUCLEO-WB55RG board */
static const struct pin_config pinconf[] = {
#ifdef CONFIG_UART_1
	{STM32_PIN_PB7, STM32WBX_PINMUX_FUNC_PB7_USART1_RX},
	{STM32_PIN_PB6, STM32WBX_PINMUX_FUNC_PB6_USART1_TX},
#endif	/* CONFIG_UART_1 */
#ifdef CONFIG_LPUART_1
	{STM32_PIN_PA2, STM32WBX_PINMUX_FUNC_PA2_LPUART1_TX},
	{STM32_PIN_PA3, STM32WBX_PINMUX_FUNC_PA3_LPUART1_RX},
#endif	/* CONFIG_LPUART_1 */
#ifdef CONFIG_I2C_1
	{STM32_PIN_PB8, STM32WBX_PINMUX_FUNC_PB8_I2C1_SCL},
	{STM32_PIN_PB9, STM32WBX_PINMUX_FUNC_PB9_I2C1_SDA},
#endif /* CONFIG_I2C_1 */
#ifdef CONFIG_I2C_3
	{STM32_PIN_PC0, STM32WBX_PINMUX_FUNC_PC0_I2C3_SCL},
	{STM32_PIN_PC1, STM32WBX_PINMUX_FUNC_PC1_I2C3_SDA},
#endif /* CONFIG_I2C_3 */
#ifdef CONFIG_SPI_1
	{STM32_PIN_PA4, STM32WBX_PINMUX_FUNC_PA4_SPI1_NSS},
	{STM32_PIN_PA5, STM32WBX_PINMUX_FUNC_PA5_SPI1_SCK},
	{STM32_PIN_PA6, STM32WBX_PINMUX_FUNC_PA6_SPI1_MISO},
	{STM32_PIN_PA7, STM32WBX_PINMUX_FUNC_PA7_SPI1_MOSI},
#endif /* CONFIG_SPI_1 */
#ifdef CONFIG_PWM_STM32_2
	{STM32_PIN_PA0, STM32WBX_PINMUX_FUNC_PA0_TMR2_CH1},
#endif /* CONFIG_PWM_STM32_2 */
};

static int pinmux_stm32_init(struct device *port)
{
	ARG_UNUSED(port);

	stm32_setup_pins(pinconf, ARRAY_SIZE(pinconf));

	return 0;
}

SYS_INIT(pinmux_stm32_init, PRE_KERNEL_1,
	 CONFIG_PINMUX_STM32_DEVICE_INITIALIZATION_PRIORITY);
