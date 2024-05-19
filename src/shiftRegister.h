//Initialize GPIO pins
void setupShiftRegisterGPIO();
//Returns the upper 8 address lines of GBA (A17-A24) as a unsigned int
uint8_t getShiftRegisterInput();
//latches shift registers inputs
void latch();
