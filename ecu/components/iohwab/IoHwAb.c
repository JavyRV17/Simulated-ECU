#include "IoHwAb.h"
#include "Dio.h"

#include "Dio_Cfg.h"

void IoHwAb_PLightState_WriteChannel(int value) {

    Dio_WriteChannel(DIO_CHANNEL_LED, value); 
}