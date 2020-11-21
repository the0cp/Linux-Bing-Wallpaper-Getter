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
  downloadImg(time, user);
  excu(time, user, deskenv);
  return 0;
}
