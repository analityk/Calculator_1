#ifndef delay_h__
#define delay_h__

#include <avr/io.h>
#include <avr/interrupt.h>

void delay_ms(uint8_t ms);
void delay_us(uint8_t us);

void delay(uint32_t volatile t);

uint16_t Millis(void);
uint8_t startMillis(void);
uint8_t stopMillis(void);

#endif // delay_h__