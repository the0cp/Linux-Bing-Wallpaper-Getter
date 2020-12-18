#include "../include/proc.h"
#include "../include/color.h"
void usage()
{
	printf(NONE"Usage: bingbg [argument]\n\n");
	printf(NONE"Arguments:\n");
	printf(NONE"(no arg)\tdefault -- download wallpaper and set background\n");
	printf(NONE"-d\t\tdefault -- download wallpaper and set background\n");
	printf(NONE"-s\t\tstore -- just download this time\n");
	printf(NONE"-h\t\thelp -- show help & usage\n");
	printf(NONE"-v\t\tversion -- show current version\n");
	printf("\n");
}