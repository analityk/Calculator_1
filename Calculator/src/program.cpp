#include <program.h>

void Program::Run(void)
{
	while(1){
		state = windowsInterface->Action(state, windowsInterface->ReadKey() );
		switch(state){
			case sMainWindowCell:{
				windowsInterface = &inputWindow;
				windowsInterface->Draw();
			};
			default:break;
		}
	};
};
