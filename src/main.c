#include "../include/proc.h"
#include "../include/download.h"
#include "../include/write_data.h"
#include "../include/color.h"

int main(int argc, char *argv[])
{  
  int opt;
  opterr = 0;
  
  while((opt = getopt(argc, argv, "d:shv")) != -1)
  if(argc == 1)
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
  }
  else
  {
    if(opt == 's')
    {
      char *time = geTime();
      char *user = getlogin();
      char *deskenv;
      conf(user);
      makeDir(time, user);
      downloadXml(time, user);
      downloadImg(time, user);
    }
    else if(opt == 'd')
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
    }
    else if(opt == 'h')
    {
      usage();
    }
    else if (opt == 'v')
    {
      printf(YELLOW"\nBing Backgrounds Getter v1.2.1\n\n");
    }
    else
    {
      usage();
    }
    
  }
  
  return 0;
}
