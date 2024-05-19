#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "address.h"
#include "shiftRegister.h"

/*
Connections between Pico, GBA, Shift Register and SD Card

GBA:
A1-A16 ->  Pico's GP0-GP15
A17-A24 -> Shift Register Inputs
WR -> GP20
RD -> GP28
CS1 -> GP27
CS2 -> Unconnected (For Now)

Shift Register:
Latch -> GP22
Clock -> GP26
Output ->GP21

SD Card:
MISO -> GP16
CS -> GP17
CLK -> GP18
MOSI -> GP19
*/

#define A1 0
#define A16 15

#define pinMask 65535

#define WR 20
#define RD 28
#define CS1 27

void setupAddressGPIO(){
    setupShiftRegisterGPIO();
    for (int pin = A1; pin < A16; ++pin ){ //For all address pins
        gpio_init(pin);
    }
    gpio_init(WR);
    gpio_set_dir(WR, GPIO_IN);
    gpio_init(RD);
    gpio_set_dir(RD, GPIO_IN);
    gpio_init(CS1);
    gpio_set_dir(CS1, GPIO_IN);


}

uint32_t getAddress(){
    //Enable pins as input
   gpio_set_dir_in_masked(pinMask);

    uint32_t addr = 0;
    for (unsigned int pin = A1; pin < A16; ++pin){
        addr += (gpio_get(A1)<<pin); //every value is shifted by appropriate pin number
    }
    addr += getShiftRegisterInput() << 16; //Add the upper 8 bits of address
    return addr;
}

void nextSequentialAddr(){

    
}

void outputData(uint32_t data){
    //Enable pins as output
    gpio_set_dir_out_masked(pinMask);
    gpio_put_masked(pinMask, data);
}



