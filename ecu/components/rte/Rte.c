#include "Rte.h"

//COMPUMETHODS WERE ENUMS OF THESE DATATYPE

//Datatype of connection from HeadlightsKnow and Headlights
//Connected by an interface creating these functions and 
//static variable 
static uint8 lightStatus;

void Rte_Write_KnobStatus(uint8 value)
{
    //Is there a way to make it more safer or more specific? 
    lightStatus = value;
}

void Rte_Read_KnobStatus(uint8* value)
{
    *value = lightStatus;
}