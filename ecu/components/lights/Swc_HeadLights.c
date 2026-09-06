#include "Swc_HeadLights.h"
#include "Rte.h"
#include "IoHwAb.h"

void Runnable_HeadLights_5ms(void) {
    
    uint8 lightState = 0;

    Rte_Read_KnobStatus(&lightState);

    //TODO: This should be abstracted in a RTE function
    //This should be server port 
    IoHwAb_PLightState_WriteChannel((int)lightState);
}