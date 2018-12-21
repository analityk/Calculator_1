#ifndef cell_h__
#define cell_h__

#include <avr/io.h>
#include <sram.h>
#include <array.h>
#include <serial.h>
#include <rpn.h>

#define MAX_CHAR_CNT	96;
#define MAX_RESULT_CNT	4;

class Cell{
public:
	ram_grip rg_string;
	ram_grip rg_formatedOutput;
	
	double result;

	
	Cell():result(0.0){
		rg_string = ram.get_mem(100);
		rg_formatedOutput = ram.get_mem(20);
		ram.clr_block(rg_string, 100);
		ram.clr_block(rg_formatedOutput, 20);
	};
	
	void Store(array<uint8_t>* inpstr){
		if(inpstr->cnts() > 0){
			ram.write_block(rg_string, 0, inpstr->size(), inpstr->data);
			result = rpn.TryCalculate(*inpstr);
		}else{
			ram.clr_block(rg_string, 100);
			result = 0.0;
		};
		
	};
	
	void Load(array<uint8_t>* inpstr){
		uint8_t t[90];
		ram.read_block(rg_string, 0, inpstr->size(), t);
		inpstr->erase();
		for(uint8_t i=0; i<inpstr->size(); i++){
			if(t[i] == 0)continue;
			inpstr->insert(t[i]);
		};
	};
	
	double Result(void){
		return result;
	};

};

#endif // cell_h__
