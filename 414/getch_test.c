#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main()
{

	initscr();
	noecho();
	cbreak();
	timeout(100);

	char c = 0x0;
	while(1)
	{
		sleep(1);
		c = (char) getch();
		printf("%x\n",c);
	}

	endwin();
	nocbreak();
}
