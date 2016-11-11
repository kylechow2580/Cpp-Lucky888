// Lucky888.cpp : main project file.

#include "stdafx.h"
#include "login.h"

using namespace Lucky888;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Login());
	return 0;
}
