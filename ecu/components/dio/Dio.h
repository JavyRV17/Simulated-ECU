#ifndef DIO_H
#define DIO_H

//Inlcuded in component base, since it must be a common file for the rest of layers (PORT, ADC, etc. )
#include "Std_Types.h"

typedef uint8 Dio_ChannelType; //This holds the pin of each port to be get/set, according to the documentation
typedef uint8 Dio_LevelType; 

void Dio_WriteChannel(Dio_ChannelType channelId, Dio_LevelType level);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelId);

#endif