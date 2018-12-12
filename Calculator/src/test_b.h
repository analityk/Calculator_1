#ifndef test_b_h__
#define test_b_h__

#include <avr/io.h>
#include <states.h>
#include <WindowsInterface.h>

class ob : public WindowsInterface {
	public:
	ob(){
		Text.ClrScr();
		Text.GoTo(0,0);
		Text.Write("constructor oa \n");
	};
	
	virtual States Action(States s, uint8_t key){
		Text.ClrScr();
		Text.GoTo(0,0);
		Text.Write("oa override Action\n");
		return sMainWindow;
	};
	
	virtual uint8_t ReadKey(void){
		return 'a';
	};
	
	virtual void Draw(void){
		return;
	};
};

#endif // test_b_h__
