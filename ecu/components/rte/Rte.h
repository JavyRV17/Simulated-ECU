#ifndef RTE_H
#define RTE_H

#include "Std_Types.h"

void Rte_Write_KnobStatus(uint8);
void Rte_Read_KnobStatus(uint8 *);

                            //Input parameter
void Rte_Call_SetHeadLights(uint8);
void Rte_Call_GetHeadLightsButton(uint8 *);

#endif