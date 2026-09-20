#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "Port.h"
#include "Port_Cfg.h"

#include "Swc_HeadLightsKnob.h"
#include "Swc_HeadLights.h"

//For CAN signals simulation
#include "driver/uart.h"

void CANframeHB(void *pvParameters)
{
    char msg = 'H';

    while(1) 
    {
        // uart_write_bytes(UART_NUM_0, &msg, 1);
        // printf("HB | CPU = %d\n", xPortGetCoreID());

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void CANframeVehicleStatus(void *pvParameters)
{

    //Fixed CAN frame   SOF    ID  LENGHT DATA -----------------------------------------
    uint8_t frame[] =  { 0xAA, 0x20, 0x07, 0x5A, 0x23, 0x09, 0x03, 0x4B, 0x58, 0x8F, 0x00 };
    uint8_t frame2[] = { 0xAA, 0x21, 0x07, 0x5A, 0x23, 0x08, 0x03, 0x4B, 0x57, 0x8F, 0x00 };

    uint8_t *ptrFrame = frame;
    int counter = 0;

    while(1) 
    {
        if(counter % 2 == 0 ) 
        {
            ptrFrame = frame;
        } else 
        {
            ptrFrame = frame2;
        }

        //UART_NUM_0 -> enum that indicates which UART channel want to use 
        //frame -> pointer identifies the first element in this case of frame 
        //sizeof(frame) -> lenght, can be fixed or determined by sizeof 
        uart_write_bytes(UART_NUM_0, ptrFrame, sizeof(frame));

        counter++;

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void CANframeCabinStatu(void *pvParameters)
{
    while(1) 
    {
        // printf("CabinStatus | CPU = %d\n", xPortGetCoreID());

        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}

//AUTOSAR runnables in here?
//Should be encapsulated in task functions? 
void HeadlightsIo(void *pvParameters)
{
    while(1)
    {
        Runnable_HeadLightsKnob_500ms(); 
        Runnable_HeadLights_500ms();

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void app_main(void) {

    Port_Init(&Port_Config);

        //Set of UART 
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    //Apply previous config and set UART_NUM_0
    uart_param_config(UART_NUM_0, &uart_config);

    //Create software layer to use UART_0
    uart_driver_install(UART_NUM_0, 1024, 0, 0, NULL, 0);

    //SWCs tasks
    xTaskCreatePinnedToCore(HeadlightsIo, "IO", 4096, NULL, 5, NULL, 0);

    //CAN simulation tasks
    xTaskCreatePinnedToCore(CANframeHB, "HB", 4096, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(CANframeVehicleStatus, "VS", 4096, NULL, 4, NULL, 0);
    xTaskCreatePinnedToCore(CANframeCabinStatu, "CS", 4096, NULL, 1, NULL, 0);


}










//DEBUGGING PORTS
// #include "driver/gpio.h"

// void app_main(void) {
// while (1)
// {
//     int level = gpio_get_level(GPIO_NUM_23);

//     printf("GPIO23 = %d\n", level);

//     vTaskDelay(pdMS_TO_TICKS(500));
// }
// }