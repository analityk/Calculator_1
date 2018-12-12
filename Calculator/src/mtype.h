#ifndef mtype_h__
#define mtype_h__

#include <avr/io.h>

class muint8{
public:
	uint8_t t;
	muint8():t(0){};
	muint8(uint8_t i):t(i){};	
};

class muint16{
public:
	uint16_t t;
	muint16():t(0){};
	muint16(uint16_t i):t(i){};
};

#endif // mtype_h__
