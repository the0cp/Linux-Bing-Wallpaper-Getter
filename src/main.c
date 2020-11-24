#include "../include/proc.h"
#include "../include/download.h"
#include "../include/write_data.h"
#include "../include/color.h"

int main()
{  
  char *time = geTime();
  char *user = getlogin();
  char *deskenv;
  conf(user);
  makeDir(time, user);
  deskenv = readConf();
  downloadXml(time, user);
  if(downloadImg(time, user) == 0)
  {
    excu(time, user, deskenv);
  }
  else
  {
    printf(RED"FAILED TO DOWNLOAD WALLPAPER!!!\n");
  }
  return 0;
}
