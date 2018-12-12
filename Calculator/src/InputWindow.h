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
	uint8_t inputKey;
	
	uint8_t letter;
	uint8_t row;
	uint8_t addressedCell;

	InputWindow():k(InputKeys), inputKey(0), letter(255), row(255), addressedCell(255) {};

	virtual States Action(States s, uint8_t key);
	virtual uint8_t ReadKey(void);
	virtual void Draw(void);
	
};

#endif // window_input_h__