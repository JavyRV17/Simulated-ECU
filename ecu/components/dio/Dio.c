#include "Dio.h"
#include "Dio_Cfg.h"
#include "driver/gpio.h"

Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelId) 
{
    //Here we should call the register directly and set/get data?
    Dio_LevelType currentLevel = gpio_get_level(Dio_ChannelHwMapD[(int)channelId]);
    return currentLevel;
}

void Dio_WriteChannel(Dio_ChannelType channelId, Dio_LevelType level)
{
    //Here we should call the register directly and set/get data?
    gpio_set_level(Dio_ChannelHwMapD[(int)channelId], level);
}
