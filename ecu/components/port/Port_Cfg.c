#include "Port_Cfg.h"
#include "driver/gpio.h"

#include "Port.h"

//Non AUTOSAR oficial documentation
//This is used as array to store all the available IDs and configuration 
static const Port_PinConfigType Port_PinConfig[] = 
{
    {             
        .pinType = PORT_PIN_LED,   //IDs from Port_Cfg.h
        .direction = PORT_PIN_OUT,  
        .modeType = PORT_PIN_MODE_DIO
    },

    {    
        .pinType = PORT_PIN_BUTTON,       //IDs from Port_Cfg.h
        .direction = PORT_PIN_IN,
        .modeType = PORT_PIN_MODE_DIO
        
    },

    {    
        .pinType = PORT_PIN_POT,           //IDs from Port_Cfg.h
        .direction = PORT_PIN_IN,
        .modeType = PORT_PIN_MODE_ADC
    }
};

//This holds all the previous PIN added manually according the PIN configuration.
//Declared previous in Port_Cfg.h as extern. So this variable can be used in several modules.
const Port_ConfigType Port_Config = {
    .Pins = Port_PinConfig,     
    .numPins = sizeof(Port_PinConfig) / sizeof(Port_PinConfig[0])
};