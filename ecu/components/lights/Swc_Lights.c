#include "IoHwAb.h"
#include "Swc_Lights.h"

void Swc_Lights_Run(void) {
    static uint8 state = 0; 

    IoHwAb_PLightState_WriteChannel((int)state);
 
    state = !state; 
}