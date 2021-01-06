#include "../include/proc.h"
#include "../include/color.h"

int checkFile(char *TIME_CF, char *USRNAME)
{
	int kb_yn;
	int kb_yn_s;
	char *imgPath;
	asprintf(&imgPath, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_CF, "/Wallpaper.png");
	if(access(imgPath, 0) == -1)
	{
		printf(RED"Warning: Wallpaper is already exist, overwrite?");
		printf(NONE" [y/n]");
		while(kb_yn = getchar())
		{
			if(kb_yn == 121)	//get 'y'
			{
				printf(L_GREEN"<OVERWRITE...>\n");
				return 0;
			}
			else if(kb_yn == 110)	//get 'n'
			{
				printf(GREEN"<DO NOT OVERWRITE>\n");
				return 1;	
			}
			else
			{
				printf(RED"Please input a vaild value!!!:"NONE);
			}
		}
	}
}