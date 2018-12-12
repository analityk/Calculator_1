#ifndef program_h__
#define program_h__

#include <avr/io.h>
#include <stdlib.h>
#include <array.h>
#include <spi.h>
#include <rpn.h>
#include <adc.h>
#include <text.h>
#include <touch.h>
#include <MainWindow.h>
#include <InputWindow.h>
#include <serial.h>
#include <sheet.h>
#include <states.h>
#include <WindowsInterface.h>

class Program{
	public:
	WindowsInterface* windowsInterface;
	MainWindow mainWindow;
	InputWindow inputWindow;
	Sheet sheet;
	array<uint8_t> inputString;
	
	uint8_t key;
	
	States state;

	Program():windowsInterface(&mainWindow), inputString(90), key(0), state(sMainWindow){
		mainWindow.Draw();
	};
	
	void Run(void);
	void WriteRawInput(void);
};

#endif // program_h__
