#ifndef window_input_h__
#define window_input_h__

#include <avr/io.h>
#include <array.h>
#include <pair.h>
#include <text.h>
#include <keys.h>
#include <states.h>
#include <touch.h>
#include <WindowsInterface.h>
#include <mtype.h>

class InputWindow: public WindowsInterface{
	public:
	Keys k;
	array<uint8_t> inputString;

	InputWindow():k(InputKeys), inputString(90) {};

	virtual States Action(States s, uint8_t key);
	virtual uint8_t ReadKey(void);
	virtual void Draw(void);
	
};

#endif // window_input_h__