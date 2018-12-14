#ifndef sheet_h__
#define sheet_h__

#include <avr/io.h>
#include <cell.h>

class Sheet{
public:
	uint8_t cell_address;	// represents actual visible left upper cell
							// calc have cells form A to J (10) and from 1 to 10 (100 cells) 
	Cell cells[100];

	Sheet():cell_address(0){};
	
};


#endif // sheet_h__
