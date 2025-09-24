/* main.c - Application main entry point */

/*
 * Copyright (c) 2015-2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/autoconf.h>
#include <zephyr/logging/log.h>

#define LOG_MODULE_NAME bttester_main
LOG_MODULE_REGISTER(LOG_MODULE_NAME, CONFIG_BTTESTER_LOG_LEVEL);

#include "btp/btp.h"
#define GPIO_ENABLE 1
#ifdef GPIO_ENABLE
extern void tput_gpio_init(void);
#endif //GPIO_ENABLE
int main(void)
{
#ifdef GPIO_ENABLE
    //tput_gpio_init();
#endif //GPIO_ENABLE
	tester_init();
	return 0;
}
