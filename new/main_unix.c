// 6 april 2015
#include "uipriv_unix.h"

// #qo pkg-config: gtk+-3.0

void uiMain(void)
{
	gtk_main();
}

void uiQuit(void)
{
	gtk_main_quit();
}
