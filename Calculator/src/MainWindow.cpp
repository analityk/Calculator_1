#include <MainWindow.h>


States MainWindow::Action(States s, uint8_t key)
{
	switch(key){
		case 200:{
			DecLine();
			return sMainWindowNavi;
		};
		case 201:{
			IncLine();
			return sMainWindowNavi;
		};
		case 202:{
			DecCol();
			return sMainWindowNavi;
		};
		case 203:{
			IncCol();
			return sMainWindowNavi;
		};
		case 204:{
			addressedCells = ActLine() * 10 + ActColumn();
			Text.ClrScr();
			return sMainWindowCell;
		};
		case 205:{
			addressedCells = (ActLine() + 1) * 10 + ActColumn();
			Text.ClrScr();
			return sMainWindowCell;
		};
		case 206:{
			addressedCells = ActLine() * 10 + ActColumn()+1;
			Text.ClrScr();
			return sMainWindowCell;
		};
		case 207:{
			addressedCells = (ActLine() + 1) * 10 + ActColumn()+1;
			Text.ClrScr();
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
	
	uint8_t letter = ActColumn();
	uint8_t row = ActLine();
	
	uint8_t adrc = (row * 10) + letter;
	
	double pd[4];
	
	pd[0] = pc[adrc].result;
	pd[1] = pc[(adrc+1) * 10].result;
	pd[2] = pc[adrc+1].result;
	pd[3] = pc[((adrc+1)*10)+1].result;
	
	uint8_t tab[4][20];
	

	for(uint8_t i=0; i<4; i++){
		FormatOutput(&pd[i], tab[i]);
	};
	//
	Text.GoToAbs(10, 2);
	Text.Write(tab[0]);
	Text.GoToAbs(10, 5);
	Text.Write(tab[1]);
	Text.GoToAbs(65, 2);
	Text.Write(tab[2]);
	Text.GoToAbs(65, 5);
	Text.Write(tab[3]);
		
};

void MainWindow::FormatOutput(double* pd, uint8_t* ps)
{
	if( (*pd > 9999999.9) || (*pd < -999999.9) ){
		dtostre(*pd, (char*)(ps), 4, 0);
		return;	
	};
	
	if( (*pd > 999999.9) || (*pd < -99999.9) ){
		dtostrf(*pd, 6, 0, (char*)(ps));
		return;
	};
	
	if( (*pd > 99999.99)||(*pd < -9999.99) ){
		dtostrf(*pd, 6, 1, (char*)(ps));
		return;
	};
	
	if( (*pd > 9999.999) || (*pd < -999.999) ){
		dtostrf(*pd, 6, 2, (char*)(ps));
		return;
	};
	
	if( (*pd > 999.9999) || (*pd < -99.9999) ){
		dtostrf(*pd, 6, 3, (char*)(ps));
		return;
	};
	
	if( (*pd > 99.99999) || (*pd < -9.99999) ){
		dtostrf(*pd, 6, 4, (char*)(ps));
		return;
	};
	
	if( (*pd > 9.999999) || (*pd < -0.0099999) ){
		dtostrf(*pd, 6, 5, (char*)(ps));
		return;
	};
	
	if(*pd > 0.00099999){
		dtostrf(*pd, 6, 6, (char*)(ps));
		return;
	};	
	
	if( (*pd > 0.0) || (*pd < 0.0) ){
		dtostre(*pd, (char*)(ps), 4, 0);
		return;
	};
	
	if(*pd == 0.0){
		strcpy((char*)(ps), "   0.0 ");
		return;
	};
	
};

uint8_t MainWindow::ReadKey(void)
{
	return k.ReadKey(k.kt, touch.ReadKey());
};

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