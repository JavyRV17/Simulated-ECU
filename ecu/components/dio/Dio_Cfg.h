#ifndef DIO_CFG_H
#define DIO_CFG_H 

#include "Dio.h"
#include "driver/gpio.h"

//Are used? Are necessary?
#define DIO_CHANNEL_LED        ((Dio_ChannelType)0u) 
#define DIO_CHANNEL_BUTTON     ((Dio_ChannelType)1u)

extern const gpio_num_t Dio_ChannelHwMapD[]; 

#endif