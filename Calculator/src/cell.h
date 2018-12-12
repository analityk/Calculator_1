#ifndef cell_h__
#define cell_h__

#include <avr/io.h>
#include <sram.h>
#include <array.h>

#define MAX_CHAR_CNT	96;
#define MAX_RESULT_CNT	4;

class Cell{
public:
	ram_grip rg_string;
	double result;
	
	Cell():result(0.0){
		rg_string = ram.get_mem(100);
	};
	
	double Result(void){
		return result;
	};
	
	double Calculate(void){
		return 0.0;
	};

};

#endif // cell_h__
