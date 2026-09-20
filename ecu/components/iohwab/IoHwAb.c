#include "IoHwAb.h"
#include "Dio.h"

#include "Dio_Cfg.h"

//Server-Runnable? 
void IoHwAb_PLightState_WriteChannel(uint8 value) {

    Dio_WriteChannel(DIO_CHANNEL_LED, value); 
}

void IoHwAb_PLightState_ReadChannel(uint8 *value) 
{
    *value = Dio_ReadChannel(DIO_CHANNEL_BUTTON);
}