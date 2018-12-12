#include <serial.h>

Serial::Serial(void){
	this->Enable();
	this->SetUbrr(19);
};

void Serial::SetUbrr(uint16_t ubrr){
	UBRR0H = (uint8_t)(ubrr >> 8);
	UBRR0L = (uint8_t)(ubrr);
};

void Serial::Enable(void)
{
	PRR0 &=~(1<<PRUSART0);
	UCSR0B = (1<<TXEN0)|(1<<RXEN0);
};

void Serial::Disable(void)
{
	UCSR0B = (0<<TXEN0)|(0<<RXEN0);
};

void Serial::InterruptEnable_RX(void)
{
	UCSR0B |= (1<<RXCIE0);
};

void Serial::InterruptDisable_RX(void)
{
	UCSR0B &=~(1<<RXCIE0);
};

void Serial::write(uint8_t* buff, uint8_t size){
	for(uint8_t i=0; i<size; i++){
		while(!(UCSR0A & (1<<UDRE0))){};
		UDR0 =buff[i];
	};
};

void Serial::write(const char* s, uint8_t size){
	write( (uint8_t*)s, size);
};

void Serial::write(char* t){
	while(*t){
		while(!(UCSR0A & (1<<UDRE0))){};
		UDR0 = *t++;
	};
};

void Serial::write(const char* s){
	while(*s){
		while(!(UCSR0A & (1<<UDRE0))){};
		UDR0 = *s++;
	};
};

void Serial::write(uint8_t byte)
{
	while(!(UCSR0A & (1<<UDRE0))){};
	UDR0 = byte;
}

void Serial::write(array<uint8_t> &data)
{
	for(uint8_t i=0; i<data.cnts(); i++){
		if( data[i] == 0 )break;
		if( data[i] == '\n' ){
			serial.write( (uint8_t) data[i]);
			break;
		};
		
		serial.write( (uint8_t) data[i]);
	};
};

uint8_t Serial::readByte(){
	while(!(UCSR0A & (1<<RXC0))){};
	return(UDR0);
};

Serial serial;