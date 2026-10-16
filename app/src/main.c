/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 1

int main(void) {
    if (BTN_init() < 0) {
        return 0;
    }

    if (LED_init() < 0) {
        return 0;
    }

    // Check and print button status
    const char *status = NULL;

    if (BTN_is_pressed(BTN0)) {
        status = "Button pressed";
    }



    while (1) {
        printk("Status: %s\n", status);
        k_msleep(SLEEP_MS);
    }

    return 0;
}


