#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define shiftLatch 22
#define shiftClock 26
#define shiftOutput 21

#define HIGH 1
#define LOW 0

//Initialize GPIO pins for Shift Register
void setupShiftRegisterGPIO(){
    gpio_init(shiftLatch);
    gpio_set_dir(shiftLatch, GPIO_OUT);
    gpio_init(shiftClock);
    gpio_set_dir(shiftClock, GPIO_OUT);
    gpio_init(shiftOutput);
    gpio_set_dir(shiftOutput, GPIO_IN);

    gpio_put(shiftLatch, HIGH); //Default, since active low.
}
//latches shift registers inputs, active low
void latch(){
    gpio_put(shiftLatch, LOW);
    //wait 
    gpio_put(shiftLatch, HIGH);
    
    

}
//Returns the upper 8 address lines of GBA (A17-A24) as a unsigned int
uint8_t getShiftRegisterInput(){
    uint8_t addr = 0;
    latch();
    for (int i = 0; i < 8; ++i){ 
    addr += (gpio_get(shiftOutput)<<i); //H goes out first, which is also the LSB
    }
    return addr;
}


