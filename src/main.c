#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>

#include "pico/stdlib.h"


void blink_led(){

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_put(LED_PIN, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }


}

int main() {

    xTaskCreate(blink_led, "Blink_led_task", 256, NULL, 1, NULL);
    vTaskStartScheduler();


}
