#include "../include/proc.h"
#include "../include/download.h"
#include "../include/color.h"

void excu(char *TIME_EX, char *USRNAME, char *DE)
{
	const char *GNOME = "GNOME";
	const char *MATE = "MATE";
	const char *NOTINGBAD = "BAD";
	char *picUri;
	pid_t status;
	asprintf(&picUri, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_EX, "/Wallpaper.jpg");
	if(*DE == *GNOME)
	{
		printf(NONE"Setting Background(GNOME3)...\n");
		char *gnome_com;
		asprintf(&gnome_com, "%s%s%s%s", "gsettings set org.gnome.desktop.background picture-uri ", "\"", picUri, "\"");
		status = system(gnome_com);
		if(status == -1)
		{
			printf(RED"Cannot set background!!!(systen error...)\n");
			exit(1);
		}
		else
		{
			if(WIFEXITED(status))
			{
				if(WEXITSTATUS(status) == 0)
				{
					printf(YELLOW"Successfully!!!\n");
				}
				else
				{
					printf(RED"Cannot set background!!!(run error: %d)\n", WEXITSTATUS(status));
				}
			}
			else
			{
				printf(RED"exit code %d \n", WEXITSTATUS(status));
			}
		}
	}
	else if(*DE == *MATE)
	{
		printf(NONE"Setting Background(MATE)...\n");
		char *mate_com;
		asprintf(&mate_com, "%s%s%s%s", "gsettings set org.mate.background picture-filename ", "\"", picUri, "\"");
		status = system(mate_com);
		if(status == -1)
		{
			printf(RED"Cannot set background!!!(systen error...)\n");
			exit(1);
		}
		else
		{
			if(WIFEXITED(status))
			{
				if(WEXITSTATUS(status) == 0)
				{
					printf(YELLOW"Successfully!!!\n");
				}
				else
				{
					printf(RED"Cannot set background!!!(run error: %d)\n", WEXITSTATUS(status));
				}
			}
			else
			{
				printf(RED"exit code %d \n", WEXITSTATUS(status));
			}
		}
	}
	else if(*DE == *NOTINGBAD)
	{
		printf(YELLOW"Setting Background(BING! Nothing Done)...\n");
	}
	free(DE);
	free(picUri);
}