#include "../include/proc.h"
#include "../include/download.h"
#include "../include/write_data.h"

int main()
{  
  char *time = geTime();
  makeDir(time);
  downloadXml(time);
  downloadImg(time);
  return 0;
}
