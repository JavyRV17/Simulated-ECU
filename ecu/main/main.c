#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "Port.h"
#include "Port_Cfg.h"

#include "Swc_Lights.h"

void app_main(void) {

    Port_Init(&Port_Config);

    while(1) {

        //What is taken from SWC are the runnables, that are attached to tasks 
        Swc_Lights_Run(); 

        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}

