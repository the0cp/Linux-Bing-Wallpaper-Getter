#include "../include/proc.h"
#include "../include/download.h"
#include "../include/color.h"

void excu(char *TIME_EX, char *USRNAME)
{
	char *pdEnv;
	pdEnv = readConf();
	const char *GNOME = "GNOME";
	const char *MATE = "MATE";
	char *picUri;
	asprintf(&picUri, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_EX, "/Wallpaper.jpg");
	if(*pdEnv == *GNOME)
	{
		printf(NONE"Setting Background(GNOME3)...\n");
		char *gnome_com;
		asprintf(&gnome_com, "%s%s%s%s", "gsettings set org.gnome.desktop.background picture-uri ", "\"", picUri, "\"");
		if(!system(gnome_com))
		{
			printf(RED"Cannot set background, please check the config file and your desktop environment!!!\n");
			exit(1);
		}
		else
		{
			printf(YELLOW"Successfully!!!\n");
		}
	}
	else if(*pdEnv == *MATE)
	{
		printf(NONE"Setting Background(MATE)...\n");
		char *mate_com;
		asprintf(&mate_com, "%s%s%s%s", "gsettings set org.mate.background picture-filename ", "\"", picUri, "\"");
		if(!system(mate_com))
		{
			printf(RED"Cannot set background, please check the config file and your desktop environment!!!\n");
			exit(1);
		}
		else
		{
			printf(YELLOW"Successfully!!!\n");
		}
	}
	else
	{
		printf(RED"PLEASE CHECK THE CONFIG FILE!!!\n");
		exit(1);
	}
	free(pdEnv);
	free(picUri);
}