#ifndef PORT_CFG_H
#define PORT_CFG_H

#include "Port.h"

//These are not physical pins, this is an ID requested by AUTOSAR
#define PORT_PIN_LED        ((Port_PinType)0u) 
#define PORT_PIN_BUTTON     ((Port_PinType)1u)

//Wrapper
//Here is declared the Port_Config variable, so the c must have the implementation
extern const Port_ConfigType Port_Config; 

#endif