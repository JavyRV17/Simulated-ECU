#include "Swc_HeadLightsKnob.h" 
#include "Rte.h"

void Runnable_HeadLightsKnob_5ms() 
{
    static uint8 lightState = 0;
    lightState = !lightState;

    Rte_Write_KnobStatus(lightState);
}