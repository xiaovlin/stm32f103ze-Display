#ifndef __HC595_H_
#define __HC595_H_

#include "sys.h"

void init_hc595(void);
void hc595_control(uint16_t data);
void init_view(void);

#endif
