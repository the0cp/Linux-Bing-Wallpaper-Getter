#include "../include/proc.h"

void makeDir(char *TIME_MD, char *USRNAME)
{
  char *folderPath;
  asprintf(&folderPath, "%s%s%s", "/home/", USRNAME, "/BBG-Download");
  //strcpy(folderPath, "/home/");
  //strcat(folderPath, USRNAME);
  //strcat(folderPath, "/BBG-Download");

  printf("Creating work-folder...\n");
  if (access(folderPath, 0) == -1)
  {
    mkdir(folderPath, S_IRWXO | S_IRWXU);
    printf("[%d]", *folderPath);
    printf("Successful!!!\n");
  }
  else
  {
    printf("[%d]", *folderPath);
    printf("Folder is already created!!\n");
  }
  free(folderPath);
  asprintf(&folderPath, "%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_MD);

  if (access(folderPath, 0) == -1)
  {
    printf("Creating download folder...\n");
    mkdir(folderPath, S_IRWXO | S_IRWXU);
    printf("[%d]", *folderPath);
    printf("Successful!!!\n");
  }
  else
  {
    printf("[%d]", *folderPath);
    printf("Failed to ctreate folder '%s', the folder may be exist!!!\n", folderPath);
  }
  free(folderPath);
}
