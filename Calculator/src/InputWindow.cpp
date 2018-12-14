#include <InputWindow.h>

States InputWindow::Action(States s, uint8_t key)
{
	if( (key > 31) && (key < 127) ){
		inputKey = key;
		return sInputWindowAscii;
	};
	
	switch(key){
		case 200:{
			return sInputWindowCLR;
		};
		case 204:{
			return sInputWindowBackspace;
		};
		case 205:{
			Text.ClrScr();
			return sInputWindowOK;
		};
		default:break;
	};

	return sInputWindow;
};

void InputWindow::Draw(void)
{
	Text.SetSpaces(1);
	Text.GoTo(0,0);
	Text.Write("             REF \x81 OK\n");

	Text.SetSpaces(1);
	Text.GoTo(0,1);
	Text.Write("=                    \n");

	Text.SetSpaces(0);
	Text.GoTo(0,2);
	Text.Write("=========================\n");

	Text.SetSpaces(4);

	Text.GoTo(0,3);
	Text.Write("qwertyuiop(789\n");

	Text.GoTo(0,4);
	Text.Write("asdfghjkl^)654\n");

	Text.GoTo(0,5);
	Text.Write("zxcvbnm_:*+321\n");

	Text.GoTo(0,6);
	Text.Write("        !/-0.,\n");

	Text.SetSpaces(1);
	Text.GoTo(0,7);
	Text.Write("CLR HELP BASE\n");
	
	if( addressedCell < 255 ){
		uint8_t t[10];
		Text.GoTo(0,0);
		uint8_t letter = (addressedCell % 10) + 65;
		uint8_t row = (addressedCell / 10) + 49;
		Text.Write(letter);
		Text.Write(row);
		itoa(addressedCell, (char*)(t), 10);
		Text.GoTo(4,0);
		Text.Write(t);
	};
	
	Text.GoTo(1,1);
	Text.Write((char*)(rawInputString->data));
	
};

uint8_t InputWindow::ReadKey(void)
{
	return k.ReadKey(k.kt, touch.ReadKey());
};