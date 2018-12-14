#ifndef program_h__
#define program_h__

#include <avr/io.h>
#include <stdlib.h>
#include <cell.h>
#include <array.h>
#include <spi.h>
#include <rpn.h>
#include <adc.h>
#include <text.h>
#include <touch.h>
#include <MainWindow.h>
#include <InputWindow.h>
#include <serial.h>
#include <states.h>
#include <WindowsInterface.h>

class Program{
	public:
	WindowsInterface* windowsInterface;
	MainWindow mainWindow;
	InputWindow inputWindow;
	
	Cell cells[100];
	
	array<uint8_t> inputString;
	
	uint8_t addressedCell;
	
	States state;

	Program():windowsInterface(&mainWindow), inputString(90), addressedCell(0), state(sMainWindow){
		mainWindow.Draw();
		inputWindow.rawInputString = &inputString;
		mainWindow.pc = cells;
	};
	
	void Run(void);
};

#endif // program_h__
