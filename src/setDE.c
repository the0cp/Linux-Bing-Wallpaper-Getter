#include "../include/proc.h"
#include "../include/color.h"

char *setDE()
{
	char *GNOME = "GNOME";
	char *MATE = "MATE";
	char *NOTINGBAD = "BAD";
	printf(L_GREEN"*** You could change the setting whenever in home/.bingbg/config.xml ***\n");
	printf(WHITE"[1]GNOME\n");
	printf(WHITE"[2]MATE\n");
	printf(WHITE"[3]What? Just download the wallpaper!!!\n");
	printf(RED"PLEASE SELECT YOUR DENV(1):");
	
	int section; 
	scanf("%d", &section);

	if(section == 1)
	{
		return GNOME;
	}
	else if(section == 2)
	{
		return MATE;
	}
	else if(section == 3)
	{
		return NOTINGBAD;
	}
	else
	{
		printf(RED"WRONG!!!\n");
	}

}