#ifndef __CFUL_HEADER__
#define __CFUL_HEADER__


#ifndef _INC_STDIO
#include <stdio.h>
#endif

#define SET_FG_COLOR(r, g, b)		SET_COLOR(FOREGROUND, r, g, b)
#define SET_BG_COLOR(r, g, b)		SET_COLOR(BACKGROUND, r, g, b)

#define BOLD		"\033[1m"
#define DIM			"\033[2m"
#define UNDERLINE	"\033[4m"
#define BLINK		"\033[5m"
#define INVERTED	"\033[7m"
#define HIDDEN		"\033[8m"
#define RESET		"\033[0m"

#define FOREGROUND	"38"
#define BACKGROUND	"48"

#define FG_COLOR(r, g, b)	"\033[" FOREGROUND ";2;"#r";"#g";"#b"m"
#define BG_COLOR(r, g, b)	"\033[" BACKGROUND ";2;"#r";"#g";"#b"m"

int _global_cful_var_use_ansi = 0;
#define SET_ANSI_MODE(mode) _global_cful_var_use_ansi = mode

#define SET_COLOR(type, r, g, b)	do { \
	if ( _global_cful_var_use_ansi == 1 ) { \
		printf("\033[%s;5;%dm", type, rgb_ansi(r, g, b)); \
	} else { \
		printf("\033[%s;2;%d;%d;%dm", type, r, g, b); \
	} \
} while(0)

inline unsigned char rgb_ansi(unsigned char r, unsigned char g, unsigned char b)
{
	// 16: black, 231: white, 6: light blue, 36: blue green
	int ansi = 16;

	if ( r == g && g == b ) {
		if ( r < 8 ) {
			return 16;
		}

		if ( r > 248 ) {
			return 231;
		}

		return (((r - 8) / 247) * 24) + 232;
	}

	ansi += (int)(36 * ((double)r / 255 * 5));
	ansi += (int)(6 * ((double)g / 255 * 5));
	ansi += (int)((double)b / 255 * 5);

	return ansi;
}

#if !defined(_F) && defined(FG_COLOR)
#define _F FG_COLOR
#endif

#if !defined(_B) && defined(BG_COLOR)
#define _B BG_COLOR
#endif

#endif // __CFUL_HEADER__
