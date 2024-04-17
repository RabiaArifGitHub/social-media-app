#include"user.h"
int main()
{
	//for opening console window in full screen mode
	HWND x = GetConsoleWindow();
	ShowWindow(x, SW_SHOWMAXIMIZED);
	start_neon(); //start
	driver();
	return 0;
}