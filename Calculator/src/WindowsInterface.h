#ifndef WindowsInterface_h__
#define WindowsInterface_h__

#include <avr/io.h>
#include <states.h>

class WindowsInterface{
	public:
	WindowsInterface(){};
	virtual States Action(States s, uint8_t key) = 0;
	virtual uint8_t ReadKey() = 0;
	virtual void Draw() = 0;
};

#endif // WindowsInterface_h__
