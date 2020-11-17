#include "../include/proc.h"
#include "../include/color.h"

void makeDir(char *TIME_MD, char *USRNAME)
{
  char *folderPath;
  asprintf(&folderPath, "%s%s%s", "/home/", USRNAME, "/BBG-Download");
  //strcpy(folderPath, "/home/");
  //strcat(folderPath, USRNAME);
  //strcat(folderPath, "/BBG-Download");

  printf(NONE"Creating work-folder...\n");
  if (access(folderPath, 0) == -1)
  {
    mkdir(folderPath, S_IRWXO | S_IRWXU);
    printf(YELLOW"[%d]", *folderPath);
    printf(YELLOW"Successful!!!\n");
  }
  else
  {
    printf(CYAN"[%d]", *folderPath);
    printf(CYAN"Folder is already created!!\n");
  }
  free(folderPath);
  asprintf(&folderPath, "%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_MD);

  if (access(folderPath, 0) == -1)
  {
    printf(NONE"Creating download folder...\n");
    mkdir(folderPath, S_IRWXO | S_IRWXU);
    printf(YELLOW"[%d]", *folderPath);
    printf(YELLOW"Successful!!!\n");
  }
  else
  {
    printf(RED"[%d]", *folderPath);
    printf(RED"Failed to ctreate folder '%s', the folder may be exist!!!\n", folderPath);
  }
  free(folderPath);
}
