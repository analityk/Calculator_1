#include <keys.h>

uint8_t readkey(uint8_t start, uint8_t stop, uint8_t x, uint8_t y){
	for( uint8_t i=start; i<stop; i++){
		uint8_t min_x = pgm_read_byte( all_keys + (i*5) );
		uint8_t min_y = pgm_read_byte( all_keys + (i*5) + 2);
		uint8_t max_x = pgm_read_byte( all_keys + (i*5) + 1);
		uint8_t max_y = pgm_read_byte( all_keys + (i*5) + 3);
		if(  (x > min_x) && (x < max_x) && (y > min_y) && (y < max_y) ){
			return (pgm_read_byte( all_keys + (i*5) + 4));
		};
	};
	return 0;
};


uint8_t Keys::ReadKey(KeysType kk, Pair<uint16_t, uint16_t> p)
{
	switch(kk){
		case InputKeys:{
			return readkey(9, 66, p.a / 4, p.b / 4);
			break;
		};
		case MainWindowKeys:{
			return readkey(0, 9, p.a / 4, p.b / 4);
			break;
		};
		
		default:break;
	};
	return 0;
};

Keys keys;