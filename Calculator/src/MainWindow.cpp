#include <MainWindow.h>


States MainWindow::Action(States s, uint8_t key)
{
	switch(key){
		case 200:{
			DecLine();
			Draw();
			return sMainWindowNavi;
		};
		case 201:{
			IncLine();
			Draw();
			return sMainWindowNavi;
		};
		case 202:{
			DecCol();
			Draw();
			return sMainWindowNavi;
		};
		case 203:{
			IncCol();
			Draw();
			return sMainWindowNavi;
		};
		case 204:{
			addressedCells = ActLine() * 10 + ActColumn();
			return sMainWindowCell;
		};
		case 205:{
			addressedCells = ActLine() * 11 + ActColumn();
			return sMainWindowCell;
		};
		case 206:{
			addressedCells = ActLine() * 10 + ActColumn()+1;
			return sMainWindowCell;
		};
		case 207:{
			addressedCells = ActLine() * 11 + ActColumn()+1;
			return sMainWindowCell;
		};
		case 208:{
			return sMainWindow;
		};
	};
	return sMainWindow;
};


void MainWindow::Draw(void)
{
	Text.SetSpaces(1);
	Text.GoTo(0,0);
	
	Text.Write("\x88 \x81                \x80 ");
	
	Text.GoToAbs(34, 0);
	Text.Write( (char)(column+65) );
	Text.GoToAbs(91, 0);
	Text.Write( (char)(column+66) );
	
	Text.GoTo(0,2);
	Text.Write( (char)(line+49) );
	
	Text.GoTo(0,5);
	Text.Write( (char)(line+50) );
	
	Text.GoTo(0,7);
	Text.Write("\x89   OPCJE ");
	
	// wykropkowanie poziome
	for( uint8_t k=0; k<8; k+=3	){
		for( uint8_t i=6; i<126; i+=6 ){
			Lcd_KS0108.SetPixel( i, 7+(8*k));
		};
	};
	
	// wykropkowanie pionowe
	for( uint8_t k=0; k<2; k++ ){
		for( uint8_t i=0; i<60; i+=4 ){
			Lcd_KS0108.SetPixel(6+(60*k), 3+i);
		};
	};
	
	for( uint8_t i=0; i<60; i+=4 ){
		Lcd_KS0108.SetPixel(126, 3+i);
	};
};

uint8_t MainWindow::ReadKey(void)
{
	return k.ReadKey(k.kt, touch.ReadKey());
};


bool MainWindow::IsCellKey(uint8_t key)
{
	if( (key > 203) && (key < 208) ){
		return true;
	};
	return false;
};


bool MainWindow::IsNavigateKey(uint8_t key)
{
	if( (key > 199) && (key < 204) ){
		return true;
	};
	return false;
}

void MainWindow::DecLine(void)
{
	if( line > 0 )line--;
};

void MainWindow::IncLine(void)
{
	if( line < LINE_CNT_MAX )line++;
};

void MainWindow::DecCol(void)
{
	if( column > 0 )column--;
};

void MainWindow::IncCol(void)
{
	if( column < COLUMN_CNT_MAX )column++;
};

uint8_t MainWindow::ActLine(void)
{
	return line;
};

uint8_t MainWindow::ActColumn(void)
{
	return column;
};