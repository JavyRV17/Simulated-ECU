#include "Swc_HeadLightsKnob.h" 
#include "Rte.h"

void Runnable_HeadLightsKnob_500ms() 
{
    //TODO: Simulated, this should come from another DIO port
    static uint8 lightState = 0;
    // lightState = !lightState;

    //Reading the button from application
    uint8 buttonState = 0;
    Rte_Call_GetHeadLightsButton(&buttonState);

    lightState = buttonState;

    //Setting led from application
    Rte_Write_KnobStatus(lightState);
}