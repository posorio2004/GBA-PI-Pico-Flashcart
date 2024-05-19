#include <stdio.h>
#include "pico/stdlib.h"
#include "address.h"

int main() {
    stdio_init_all();
    setupAddressGPIO();
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    printf("Start");
    while (true) {
        uint32_t temp = getAddress();
        if (temp){
            printf("%d\n",temp);
        }
        //printf("Can you see me now?");
        gpio_put(PICO_DEFAULT_LED_PIN, 1);
        //sleep_ms(100);
        //gpio_put(PICO_DEFAULT_LED_PIN, 0);
    }
}
