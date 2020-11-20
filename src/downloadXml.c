#include "../include/download.h"
#include "../include/proc.h"
#include "../include/write_data.h"
#include "../include/color.h"


void downloadXml(char *TIME_XML, char *USRNAME)
{
  char *xml_url = "https://www.bing.com/HPImageArchive.aspx?format=xml&idx=0&n=1&mkt=en-US";
  printf(L_GREEN"<XML: Start downloading!!!>\n");
  CURL *curlXml;
  FILE *fpXml;
  CURLcode resXml;
  char *xmlName;
  asprintf(&xmlName, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_XML, "/index.xml");
  printf(NONE"Downloading Xml!!!\n");
  curlXml = curl_easy_init();
  if (curlXml)
  {
    fpXml = fopen(xmlName, "wb");
    curl_easy_setopt(curlXml, CURLOPT_URL, xml_url);
    curl_easy_setopt(curlXml, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curlXml, CURLOPT_WRITEDATA, fpXml);
    curl_easy_setopt (curlXml, CURLOPT_NOPROGRESS, 0);  
    printf(L_CYAN"\n");
    resXml = curl_easy_perform(curlXml);
    curl_easy_cleanup(curlXml);
    fclose(fpXml);
  }
  free(xmlName);
}
