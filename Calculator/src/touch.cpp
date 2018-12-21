#include <touch.h>

uint16_t Touch::rescale_x(uint16_t x)
{
	float dx;

	uint16_t medi = 445;
	float scale = 1.15;

	if( x > medi ){
		dx = medi + scale*(x-medi);
		}else{
		dx = medi - scale*(medi-x);
	};
	return (uint16_t)(dx);
};

uint16_t Touch::rescale_y(uint16_t y)
{
	float dy;

	uint16_t medi = 470;
	float scale = 1.45;

	if( y > medi ){
		dy = medi + scale*(y-medi);
		}else{
		dy = medi - scale*(medi-y);
	};
	return (uint16_t)(dy);
}

void Touch::wait_release_key(void)
{
	touch.delay_keypressed();
	delay(0x18000);
};

void Touch::KeyPressed(void)
{
	while( ( Adc.current_X() + Adc.current_Y() ) < 630 ){};
}

bool Touch::Press(void)
{
	if( Adc.current_X() + Adc.current_Y() < 630 ){
		return true;
	};
	return false;
}

void Touch::ReadCoordinates(void)
{
	uint16_t tx[10];
	uint16_t ty[10];
	
	KeyPressed();
	
	delay(0xFFF);
	
	for(uint8_t i=0; i<10; i++){
		tx[i] = Adc.voltage_Y();
		ty[i] = Adc.voltage_X();
	};
	
	uint16_t avx = 0;
	uint16_t avy = 0;
	
	for(uint8_t i=0; i<10; i++){
		avx += tx[i];
		avy += ty[i];
	};
	
	avx /= 10;
	avy /= 10;
	
	
	y = rescale_y(avy);
	x = rescale_x(avx);
	
};

void Touch::delay_keypressed(void)
{
	while( !touch.Press() ){};
};

Pair<uint16_t, uint16_t> Touch::ReadKey(void)
{
	touch.ReadCoordinates();
	wait_release_key();
	return Pair<uint16_t, uint16_t>(this->x, this->y);
}

Touch touch;