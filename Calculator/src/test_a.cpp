#include <test_a.h>

 oa::oa(){
	Text.ClrScr();
	Text.GoTo(0,0);
	Text.Write("constructor oa \n");
};

States oa::Action(States s, uint8_t key)
{
	Text.ClrScr();
	Text.GoTo(0,0);
	Text.Write("oa override Action\n");
	return sMainWindow;
}

uint8_t oa::ReadKey(void)
{
	return '1';
};

void oa::Draw(void)
{
	return;
};

