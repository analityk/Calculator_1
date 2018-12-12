#include <program.h>

void Program::Run(void)
{
	while(1){
		
		state = windowsInterface->Action(state, windowsInterface->ReadKey() );
		
		switch(state){
			case sMainWindowCell:{
				state = sInputWindow;
				windowsInterface = &inputWindow;
				windowsInterface->Draw();
				break;
			};
			
			case sInputWindowOK:{
				state = sMainWindow;
				windowsInterface = &mainWindow;
				windowsInterface->Draw();
				break;
			};
			
			default:break;
		}
	};
};
