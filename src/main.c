#include "main.h"

//void set_random_colour();

const int lcd_width = 240;
const int lcd_height = 135;

void blink_led();
void set_random_colour();

// lcd configuration
const struct st7789_config lcd_config = {
    // .spi      = PICO_DEFAULT_SPI_INSTANCE,
    // .gpio_din = PICO_DEFAULT_SPI_TX_PIN,
    // .gpio_clk = PICO_DEFAULT_SPI_SCK_PIN,
    // .gpio_cs  = PICO_DEFAULT_SPI_CSN_PIN,
    // .gpio_dc  = 20,
    // .gpio_rst = 21,
    // .gpio_bl  = 22,


    .spi      = PICO_DEFAULT_SPI_INSTANCE,
    .gpio_din = 11,
    .gpio_clk = 10,
    .gpio_cs  = 9,
    .gpio_dc  = 8,
    .gpio_rst = 12,
    .gpio_bl  = 13,

};


int main() {

    st7789_init(&lcd_config, lcd_width, lcd_height);

    st7789_fill(0x0000);

    xTaskCreate(blink_led, "Blink_led_task", 256, NULL, 1, NULL);

    //     while (1) {
    //     // create a random x, y, and color value
    //     int rand_x = rand() % lcd_width;
    //     int rand_y = rand() % lcd_height;
    //     uint16_t rand_color = rand() % 0xffff;
        
    //     // move the cursor to the random x and y position
    //     st7789_set_cursor(rand_x, rand_y);

    //     // put the random color as the pixel value
    //     st7789_put(rand_color);
    // }



    vTaskStartScheduler();


}

void set_random_colour()
{

    int rand_x = rand() % lcd_width;
        int rand_y = rand() % lcd_height;
        uint16_t rand_color = rand() % 0xffff;
        
        // move the cursor to the random x and y position
        st7789_set_cursor(rand_x, rand_y);

        // put the random color as the pixel value
        st7789_put(rand_color);

}


void blink_led(){

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        st7789_fill(0x0000);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        gpio_put(LED_PIN, 0);
        //st7789_fill(0xffff);
        set_random_colour();
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }


}