#ifndef MainWindow_h__
#define MainWindow_h__

#include <avr/io.h>
#include <text.h>
#include <pair.h>
#include <keys.h>
#include <states.h>
#include <touch.h>
#include <WindowsInterface.h>


#define LINE_CNT_MAX	8
#define COLUMN_CNT_MAX	8

class MainWindow: public WindowsInterface{
public:

	Keys k;
	
	uint8_t column;
	uint8_t line;
	uint8_t addressedCells;
	
	MainWindow():k(MainWindowKeys), column(0), line(0), addressedCells(0) {};
	
	
	virtual States Action(States s, uint8_t key);
	virtual uint8_t ReadKey(void);
	virtual void Draw(void);
	
	void DecLine(void);
	void IncLine(void);
	void DecCol(void);
	void IncCol(void);
	uint8_t ActLine(void);
	uint8_t ActColumn(void);
	
};

#endif // MainWindow_h__