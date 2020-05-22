#include <stdio.h>
#include "cful.h"

int main ( void )
{
	printf(BOLD "Hello World" RESET "\n");
	printf(_F(255, 196, 0) "Hello World" RESET "\n");
	printf(_B(135, 219, 70) "Hello World" RESET "\n");
	printf(_F(0, 0, 0) _B(255,255,255) "Hello World" RESET "\n");

	SET_COLOR(FOREGROUND, 129, 56, 224);
	printf("Hello World\n");

	SET_COLOR(BACKGROUND, 217, 255, 252);
	printf("Hello World" RESET "\n");

	SET_ANSI_MODE(1);

	SET_COLOR(FOREGROUND, 255, 85, 0);
	printf("Hello World\n");

	SET_COLOR(BACKGROUND, 11, 0, 0);
	printf("Hello World" RESET "\n");
	return 0;
}
