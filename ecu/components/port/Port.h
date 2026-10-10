#ifndef PORT_H
#define PORT_H

#include "Std_Types.h"

//Datatype for the symbolic name of a port pin 
//It shall be uint8 or uint16 according to the specific MCU platform
//This seems to be the specific PIN
//OFFICIAL datatype
typedef uint8 Port_PinType; 

//A type to define the direction of the PIN 
//OFFICIAL datatype
typedef enum 
{
    PORT_PIN_IN = 0u, //Why Am I using u? -> to make it sure unsigned 
    PORT_PIN_OUT, 
} Port_PinDirectionType; 

//A port pin shall be configurable with the number of port pin modes available in the MCU.
//OFFICIAL datatype
typedef enum {
    PORT_PIN_MODE_DIO,
    PORT_PIN_MODE_ADC
} Port_PinModeType;

//Non part of AUTOSAR oficial documentation, used to encapsulate config per pin
//TODO: Experimental -> what if you do not have a datatype to hold several? 
//From this we will define an array.
///NOT OFFICIAL
typedef struct {
    Port_PinType pinType;
    Port_PinDirectionType direction; 
    Port_PinModeType modeType;
} Port_PinConfigType; 

//Hardware dependant structure 
//Wrapper holding all the pins to be configured
typedef struct {
    const Port_PinConfigType *Pins; 
    uint16 numPins; 
} Port_ConfigType; 

/***********************************************Function definition*************************************************/

//Initializes the port driver module
//The function shall initialize ALL ports and port pins with the configuration set pointed to by the parameter. 
//OFFICIAL 
void Port_Init(const Port_ConfigType* ConfigPtr); 

#endif