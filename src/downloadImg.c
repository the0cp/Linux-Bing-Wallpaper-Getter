#include "../include/download.h"
#include "../include/proc.h"
#include "../include/write_data.h"

void downloadImg(char *TIME_IMG)
{
  printf("<Image: Start Downloading!!!>\n");
  CURL *curlImg;
  FILE *fpImg;
  CURLcode resImg;
  char *imgName;
  char *img_url_f = parseXml(TIME_IMG);
  asprintf(&imgName, "%s%s%s%s%s", "/home/", getlogin(), "/BBG-Download/", TIME_IMG, "/Wallpaper.jpg");
  printf("<Downloading Image!!!>\n");
  curlImg = curl_easy_init();
  if(curlImg)
  {
    fpImg = fopen(imgName, "wb");
    curl_easy_setopt(curlImg, CURLOPT_URL, img_url_f);
    curl_easy_setopt(curlImg, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curlImg, CURLOPT_WRITEDATA, fpImg);
    curl_easy_setopt(curlImg, CURLOPT_NOPROGRESS, 0);
    resImg = curl_easy_perform(curlImg);
    fclose(fpImg);
  }
  printf("[%d]Download Finished!!!\n", &imgName);
  printf("[%d]The image has been stored in%s",&imgName, imgName);
  free(imgName);
  free(img_url_f);
}
