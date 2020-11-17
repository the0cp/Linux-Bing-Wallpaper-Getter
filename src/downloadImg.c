#include "../include/download.h"
#include "../include/proc.h"
#include "../include/write_data.h"
#include "../include/color.h"

void downloadImg(char *TIME_IMG, char *USRNAME)
{
  printf(L_GREEN"<Image: Start Downloading!!!>\n");
  CURL *curlImg;
  FILE *fpImg;
  CURLcode resImg;
  char *imgName;
  char *img_url_f = parseXml(TIME_IMG, USRNAME);
  asprintf(&imgName, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_IMG, "/Wallpaper.jpg");
  printf(NONE"Downloading Image!!!\n");
  curlImg = curl_easy_init();
  if(curlImg)
  {
    fpImg = fopen(imgName, "wb");
    curl_easy_setopt(curlImg, CURLOPT_URL, img_url_f);
    curl_easy_setopt(curlImg, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curlImg, CURLOPT_WRITEDATA, fpImg);
    curl_easy_setopt(curlImg, CURLOPT_NOPROGRESS, 0);
    printf(L_CYAN"\n");
    resImg = curl_easy_perform(curlImg);
    fclose(fpImg);
  }
  printf(YELLOW"[%d]Download Finished!!!\n", &imgName);
  printf(YELLOW"[%d]The image has been stored in%s\n",&imgName, imgName);
  free(imgName);
  free(img_url_f);
}
