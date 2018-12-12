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
	uint8_t key;
	
	States state;

	Program():windowsInterface(&mainWindow), key(0), state(sMainWindow){
		mainWindow.Draw();
	};
	
	void Run(void);
		
};

#endif // program_h__
