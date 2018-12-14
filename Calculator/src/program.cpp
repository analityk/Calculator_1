#include <program.h>
#include <array.h>

void Program::Run(void)
{
	while(1){
		
		state = windowsInterface->Action(state, windowsInterface->ReadKey() );
				
		switch(state){
			case sMainWindowCell:{
				state = sInputWindow;
				
				inputWindow.addressedCell = mainWindow.addressedCells;
				addressedCell = mainWindow.addressedCells;
				
				cells[addressedCell].Load(&inputString);
				
				windowsInterface = &inputWindow;
				windowsInterface->Draw();
				break;
			};
			
			case sMainWindowNavi:{
				state = sMainWindow;
				windowsInterface->Draw();
				break;
			};
			
			case sInputWindowAscii:{
				state = sInputWindow;
				inputString.insert(inputWindow.inputKey);
				windowsInterface->Draw();
				break;
			};
			
			case sInputWindowOK:{
				state = sMainWindow;
				cells[addressedCell].Store(&inputString);				
				windowsInterface = &mainWindow;
				windowsInterface->Draw();
				break;
			};
			
			case sInputWindowCLR:{
				state = sInputWindow;
				inputString.erase();
				windowsInterface->Draw();
				break;
			};
			
			case sInputWindowBackspace:{
				state = sInputWindow;
				inputString.DelLastChar();
				windowsInterface->Draw();
				break;
			};
	
			default:break;
			
			case sMainWindow:
			break;
			case sMainWindowOptions:
			break;
			case sInputWindowHelp:
			break;
			case sInputWindowBase:
			break;
			case sInputWindowReference:
			break;
			case sInputWindow:
			break;
		};
	};
};

