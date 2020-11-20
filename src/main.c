#include "../include/proc.h"
#include "../include/download.h"
#include "../include/write_data.h"
#include "../include/color.h"

int main()
{  
  char *time = geTime();
  char *user = getlogin();
  conf(user);
  makeDir(time, user);
  downloadXml(time, user);
  downloadImg(time, user);
  excu(time, user);
  return 0;
}
