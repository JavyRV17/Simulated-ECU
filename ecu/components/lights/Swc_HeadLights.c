#include "Swc_HeadLights.h"
#include "Rte.h"
#include "IoHwAb.h"

void Runnable_HeadLights_500ms(void) {
    
    uint8 lightState = 0;

    Rte_Read_KnobStatus(&lightState);

    Rte_Call_SetHeadLights(lightState);
}