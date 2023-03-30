#include "mbed.h"

RawSerial pc(USBTX, USBRX);
DigitalOut led0(LED1), led25(LED2), led50(LED3), led75(LED4);

AnalogIn temt6000(p15);
// temt6000 breakout: VCC(to VOUT=3.3V), GND(to GND), SIG(to p15) 

int main()
{
  for(;;)
  {
    float x = temt6000;
    
    // four LEDs meaning "light level" (1 to 4):
    led0 = 1;
    led25 = led50 = led75 = 0;
    if(x>0.25) led25 = 1;
    if(x>0.50) led50 = 1;
    if(x>0.75) led75 = 1;
    
    printf("%f\r\n", x);
    wait(0.50);
  }
}