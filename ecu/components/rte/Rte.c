#include "Rte.h"
#include "IoHwAb.h"

//COMPUMETHODS WERE ENUMS OF THESE DATATYPE

//Datatype of connection from HeadlightsKnow and Headlights
//Connected by an interface creating these functions and 
//static variable 
static uint8 lightStatus;

//Read-Write ports 
void Rte_Write_KnobStatus(uint8 value)
{
    //Is there a way to make it more safer or more specific? 
    lightStatus = value;
}

void Rte_Read_KnobStatus(uint8* value)
{
    *value = lightStatus;
}

//Client-Server ports 
void Rte_Call_SetHeadLights(uint8 value)
{
    //Calling directly the IoHwAb?
    //Server Runnable
    IoHwAb_PLightState_WriteChannel((int)value);
}

void Rte_Call_GetHeadLightsButton(uint8 *value) 
{
    IoHwAb_PLightState_ReadChannel(value);
}