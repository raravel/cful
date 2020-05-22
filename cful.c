#include <stdio.h>
#include "cful.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP(x) sleep(x)
void gotoxy(int x,int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
void cursor_view(unsigned char show)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
}
#else
#include <unistd.h>
#define SLEEP(x) usleep(x * 1000)
void gotoxy(int x, int y)
{
     printf("\033[%d;%df",y,x);
}
void cursor_view(unsigned char show)
{
	if ( show ) {
		printf("\e[?25h");
	} else {
		printf("\e[?25l");
	}
}
#endif

#define clear() printf("\033[H\033[J")


void print_cful( void )
{
	gotoxy(0, 0);
	printf(" ██████╗███████╗██╗   ██╗██╗     \n");
	printf("██╔════╝██╔════╝██║   ██║██║     \n");
	printf("██║     █████╗  ██║   ██║██║     \n");
	printf("██║     ██╔══╝  ██║   ██║██║     \n");
	printf("╚██████╗██║     ╚██████╔╝███████╗\n");
	printf(RESET);
}

void one_time_print( int r, int g, int b )
{
	SET_FG_COLOR(r, g, b);
	print_cful();
	SLEEP(2);
}

#include <stdlib.h>
int main ( void )
{
	int r = 255, g = 100, b = 100;
	char a;

	cursor_view(0);
	getc(stdin);
	clear();
	do {
		while ( g < 255 ) {
			one_time_print(r, g, b);
			if ( g < 255 ) g++;
		}
		one_time_print(r, g, b);

		while ( r > 100 ) {
			one_time_print(r, g, b);
			if ( r > 100 ) r--;
		}
		one_time_print(r, g, b);

		while ( b < 255 ) {
			one_time_print(r, g, b);
			if ( b < 255 ) b++;
		}
		one_time_print(r, g, b);

		while ( g > 100 ) {
			one_time_print(r, g, b);
			if ( g > 100 ) g--;
		}
		one_time_print(r, g, b);

		while ( r < 255 ) {
			one_time_print(r, g, b);
			if ( r < 255 ) r++;
		}
		one_time_print(r, g, b);

		while ( b > 100 ) {
			one_time_print(r, g, b);
			if ( b > 100 ) b--;
		}
		one_time_print(r, g, b);
	} while ( 0 );

	return 0;
}
