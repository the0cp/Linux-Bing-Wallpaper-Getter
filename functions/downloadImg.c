#include "headers/download.h"
#include "headers/proc.h"
#include "headers/write_data.h"

void downloadImg()
{
  printf("<Image: Start Downloading!!!>\n");
  CURL *curlImg;
  FILE *fpImg;
  CURLcode resImg;
  char *imgName;
  asprintf(&imgName, "%s%s%s%s%s", "/home/", getlogin(), "/BBG-Download/", geTime(), "/Wallpaper.jpg");
  printf("<Downloading Image!!!>\n");
  curlImg = curl_easy_init();
  if(curlImg)
  {
    fpImg = fopen(imgName, "wb");
    curl_easy_setopt(curlImg, CURLOPT_URL, parseXml());
    curl_easy_setopt(curlImg, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curlImg, CURLOPT_WRITEDATA, fpImg);
    curl_easy_setopt(curlImg, CURLOPT_NOPROGRESS, 0);
    resImg = curl_easy_perform(curlImg);
    fclose(fpImg);
  }
  free(imgName);
  free(parseXml());
}
