#ifndef __CFUL_HEADER__
#define __CFUL_HEADER__


#define BOLD		"\033[1m"
#define DIM			"\033[2m"
#define UNDERLINE	"\033[4m"
#define BLINK		"\033[5m"
#define INVERTED	"\033[7m"
#define HIDDEN		"\033[8m"
#define RESET		"\033[0;0;0m"

#define FOREGROUND	"38"
#define BACKGROUND	"48"

#define FG_COLOR(r, g, b)	"\033[" FOREGROUND ";2;"#r";"#g";"#b"m"
#define BG_COLOR(r, g, b)	"\033[" BACKGROUND ";2;"#r";"#g";"#b"m"

#ifndef _INC_STDIO
#include <stdio.h>
#endif

#define SET_COLOR(type, r, g, b)	printf("\033[%s;2;%d;%d;%dm", type, r, g, b)
#define SET_FG_COLOR(r, g, b)		SET_COLOR(FOREGROUND, r, g, b)
#define SET_BG_COLOR(r, g, b)		SET_COLOR(BACKGROUND, r, g, b)

#endif