#include <InputWindow.h>

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
}


States InputWindow::Action(States s, uint8_t key)
{
	return sInputWindow;
};

uint8_t InputWindow::ReadKey(void)
{
	return k.ReadKey(k.kt, touch.ReadKey());
};