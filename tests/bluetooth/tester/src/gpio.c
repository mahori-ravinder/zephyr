#define GPIO_DEBUG
#ifdef GPIO_DEBUG

#include <zephyr/drivers/gpio.h>
#include <inttypes.h>

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

static const struct gpio_dt_spec use_led_1 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec use_led_2 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
/*
 * Get button configuration from the devicetree sw0 alias. This is mandatory.
 */
#define SW0_NODE DT_ALIAS(sw0)
#if !DT_NODE_HAS_STATUS_OKAY(SW0_NODE)
#error "Unsupported board: sw0 devicetree alias is not defined"
#endif
static const struct gpio_dt_spec button1 = GPIO_DT_SPEC_GET_OR(SW0_NODE, gpios,
                                                               {0});
static struct gpio_callback button1_cb_data;

int setup_and_check_led()
{
    if ((!gpio_is_ready_dt(&use_led_1)) || (!gpio_is_ready_dt(&use_led_2)))
    {
        return 0;
    }

    int ret1 = gpio_pin_configure_dt(&use_led_1, GPIO_OUTPUT_INACTIVE);
    if (ret1 < 0)
    {
        return 0;
    }
    int ret2 = gpio_pin_configure_dt(&use_led_2, GPIO_OUTPUT_INACTIVE);
    if (ret2 < 0)
    {
        return 0;
    }
    return 1;
}

void tput_gpio_init(void)
{
    setup_and_check_led();
}

void tput_gpio_led1_toggle(void)
{
    int ret = gpio_pin_toggle_dt(&use_led_1);
    if (ret < 0)
    {
        printk("tput_gpio_toggle_led: (err: %d)\n", ret);
    }
}

void tput_gpio_led2_toggle(void)
{
    int ret = gpio_pin_toggle_dt(&use_led_2);
    if (ret < 0)
    {
        printk("tput_gpio_toggle_led: (err: %d)\n", ret);
    }
}

#endif 