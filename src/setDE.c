#include "../include/proc.h"
#include "../include/color.h"

char *setDE()
{
	char *GNOME = "GNOME";
	char *MATE = "MATE";
	printf("[1]GNOME\n");
	printf("[2]MATE\n");
	printf(RED"PLEASE SELECT YOUR DENV(1):");
	printf(L_GREEN"*** You could change the setting whenever in home/.bingbg/config.xml ***\n");
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
	else
	{
		printf(RED"WRONG!!!\n");
	}

}