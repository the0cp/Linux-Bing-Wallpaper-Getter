#include "functions/headers/proc.h"
#include "functions/headers/download.h"
#include "functions/headers/write_data.h"

int main()
{
  makeDir();
  downloadXml();
  //parseXml();
  downloadImg();
  //free(imgName);
  return 0;
}
