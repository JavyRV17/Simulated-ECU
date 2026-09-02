#include "Port.h"
#include "driver/gpio.h"

//To initialize Port driver 
//This function will take an array of several pins to be configured.

//TODO: No correct solution, this is also declared in Dio 
//Since in the ESP32 I do not want to touch register directly 
//I use the ESP32 API internal to set PINs 
const gpio_num_t Port_ChannelHwMap[] = 
{
    GPIO_NUM_2,
    GPIO_NUM_4
};

void Port_Init(const Port_ConfigType* ConfigPtr) 
{
    uint16 i; 

    //Here we are storing in pin the pin id from the configptr array 
    //and in hwpin the pin from the local array, holding the physical PIN 
    for (i = 0; i < ConfigPtr->numPins; i++) 
    {
        Port_PinType pin = ConfigPtr->Pins[i].pinType; 

        //Port_PinType is an ID
        //And it's different to GPIO number 
        //In the Port_ChannelHwMap I'm just taking 2 ports, different order 
        //Port_PinType by going along the array, set the pin by using 
        //ESP32 functions
        gpio_num_t hwPin = Port_ChannelHwMap[(int)pin];
        
        //Reset pin, from the previous logic, relating ID with physical PIN 
        gpio_reset_pin(hwPin);
        
        //According to current PIN, it is configured as input or output
        if (ConfigPtr->Pins[i].direction == PORT_PIN_OUT) 
        {
            gpio_set_direction(hwPin, GPIO_MODE_OUTPUT); 
        }
        else 
        {
            gpio_set_direction(hwPin, GPIO_MODE_INPUT); 
        }
    }
}