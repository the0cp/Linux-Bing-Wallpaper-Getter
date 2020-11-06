#include "headers/proc.h"

void makeDir()
{
  asprintf(&folderPath, "%s%s%s", "/home/", getlogin(), "/BBG-Download");
  //strcpy(folderPath, "/home/");
  //strcat(folderPath, getlogin());
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
  asprintf(&folderPath, "%s%s%s%s", "/home/", getlogin(), "/BBG-Download/", geTime());

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
