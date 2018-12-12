#ifndef touch_h__
#define touch_h__

#include <avr/io.h>
#include <adc.h>
#include <delay.h>
#include <pair.h>

class Touch{
	private:
	uint16_t rescale_x(uint16_t x);
	uint16_t rescale_y(uint16_t y);

	public:
	uint16_t x;
	uint16_t y;
	
	Touch(){};
	void KeyPressed(void);
	bool Press(void);
	void ReadCoordinates(void);
	
	void delay_keypressed(void);

	Pair<uint16_t, uint16_t> ReadKey(void);
	
	void wait_release_key(void);
};

extern Touch touch;

#endif // touch_h__