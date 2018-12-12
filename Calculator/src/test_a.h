#ifndef test_a_h__
#define test_a_h__

#include <avr/io.h>
#include <states.h>
#include <WindowsInterface.h>
#include <text.h>

class oa : public WindowsInterface {
	public:
	oa();
	
	virtual States Action(States s, uint8_t key);
	
	
	virtual uint8_t ReadKey(void);
	
	virtual void Draw(void);
};


#endif // test_a_h__
