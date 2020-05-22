#include <stdio.h>
#include "cful.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP(x) sleep(x)
#else
#include <unistd.h>
#define SLEEP(x) usleep(x)
#endif

#define clear() printf("\033[H\033[J")

/*
 ██████╗███████╗██╗   ██╗██╗     
██╔════╝██╔════╝██║   ██║██║     
██║     █████╗  ██║   ██║██║     
██║     ██╔══╝  ██║   ██║██║     
╚██████╗██║     ╚██████╔╝███████╗
*/


void print_cful( char *fg, char *bg )
{
	printf("%s %s", fg, bg);
	printf(" ██████╗███████╗██╗   ██╗██╗     \n");
	printf("██╔════╝██╔════╝██║   ██║██║     \n");
	printf("██║     █████╗  ██║   ██║██║     \n");
	printf("██║     ██╔══╝  ██║   ██║██║     \n");
	printf("╚██████╗██║     ╚██████╔╝███████╗\n");
	printf(RESET);
}

int main ( void )
{
	int i;
	while ( 1 ) {
		for (i=100;i<=175;i++) {
			clear();
			print_cful(_F(255, i, i), _B(0, 0, 0));
			SLEEP(10);
		}

		for (i-=1;i>=100;i--) {
			clear();
			print_cful(_F(255, i, i), _B(0, 0, 0));
			SLEEP(10);
		}
	}
}
