#include <program.h>

void Program::Run(void)
{
	while(1){
		
		state = windowsInterface->Action(state, windowsInterface->ReadKey() );
		
		switch(state){
			case sMainWindowCell:{
				state = sInputWindow;
				inputWindow.addressedCell = mainWindow.addressedCells;
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
				WriteRawInput();
				break;
			};
			
			case sInputWindowOK:{
				state = sMainWindow;
				windowsInterface = &mainWindow;
				windowsInterface->Draw();
				
				inputString.erase();
				break;
			};
			
			case sInputWindowCLR:{
				state = sInputWindow;
				windowsInterface->Draw();
				inputString.erase();
				break;
			};
			
			case sInputWindowBackspace:{
				state = sInputWindow;
				windowsInterface->Draw();
				inputString.DelLastChar();
				WriteRawInput();
				break;
			};
			
			default:break;
		};
	};
};

void Program::WriteRawInput(void){
	Text.GoTo(1,1);
	Text.Write(inputString);
};

