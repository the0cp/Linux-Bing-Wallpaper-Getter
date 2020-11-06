#include "headers/download.h"
#include "headers/proc.h"
#include "headers/write_data.h"



void downloadXml()
{
  char *xml_url = "https://www.bing.com/HPImageArchive.aspx?format=xml&idx=0&n=1&mkt=en-US";
  printf("Start downloading!!!\n");
  CURL *curlXml;
  FILE *fpXml;
  CURLcode resXml;
  char *xmlName;
  asprintf(&xmlName, "%s%s%s%s%s", "/home/", getlogin(), "/BBG-Download/", geTime(), "/index.xml");
  printf("Downloading Xml!!!\n");
  curlXml = curl_easy_init();
  if (curlXml)
  {
    fpXml = fopen(xmlName, "wb");
    curl_easy_setopt(curlXml, CURLOPT_URL, xml_url);
    curl_easy_setopt(curlXml, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curlXml, CURLOPT_WRITEDATA, fpXml);
    curl_easy_setopt (curlXml, CURLOPT_NOPROGRESS, 0);
    resXml = curl_easy_perform(curlXml);
    curl_easy_cleanup(curlXml);
    fclose(fpXml);
  }
  free(xmlName);
}
