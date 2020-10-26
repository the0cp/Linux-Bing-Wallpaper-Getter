#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <curl/curl.h>
#include <libxml/tree.h>
#include <libxml/parser.h>

char *folderPath;
char *imgName;
char *img_url;
char datetime[200];

void geTime()
{
  time_t now;
  struct tm *tm_now;

  printf("[%d]Getting datetime...\n", &now);
  time(&now);
  tm_now = localtime(&now);
  strftime(datetime, 200, "%m-%d-%Y", tm_now);

  printf("[%d]Successful!!!", &now);
  printf("----------Now: %s\n", datetime);

}

void makedir()
{
  asprintf(&folderPath, "%s%s%s", "/home/", getlogin(), "/BBG-Download");
  //strcpy(folderPath, "/home/");
  //strcat(folderPath, getlogin());
  //strcat(folderPath, "/BBG-Download");

  printf("Creating work-folder...\n");
  if (access(folderPath, 0) == -1)
  {
    mkdir(folderPath, S_IRWXO | S_IRWXU);
    printf("[%d]", *folderPath);
    printf("Successful!!!\n");
  }
  else
  {
    printf("[%d]", *folderPath);
    printf("Folder is already created!!\n");
  }
  free(folderPath);
  asprintf(&folderPath, "%s%s%s%s", "/home/", getlogin(), "/BBG-Download/", datetime);

  if (access(folderPath, 0) == -1)
  {
    printf("Creating download folder...\n");
    mkdir(folderPath, S_IRWXO | S_IRWXU);
    printf("[%d]", *folderPath);
    printf("Successful!!!\n");
  }
  else
  {
    printf("[%d]", *folderPath);
    printf("Failed to ctreate folder '%s', the folder may be exist!!!\n", folderPath);
  }
  free(folderPath);
}

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  size_t written = fwrite(ptr, size, nmemb, stream);
  return written;
}

void parseXml()
{
  char *urlPart;
  char *xmlName;
  asprintf(&xmlName, "%s%s%s%s%s", "/home/", getlogin(), "/BBG-Download/", datetime, "/index.xml");
  xmlDocPtr pdoc = NULL;
  xmlNodePtr proot = NULL;
  xmlNodePtr pcur = NULL;
  
  xmlKeepBlanksDefault(0); //Blanks may be parse as a node
  pdoc = xmlReadFile(xmlName, "UTF-8", XML_PARSE_RECOVER);

  if (pdoc == NULL)
  {
    printf("error:cannot open xml!!!\n");
    exit(1);
  }

  proot = xmlDocGetRootElement(pdoc);

  if(proot == NULL)
  {
    printf("error: Xml is empty!!!\n");
    exit(1);
  }

  pcur = proot -> xmlChildrenNode;
  while (pcur != NULL)
  {
    if (!xmlStrcmp(pcur->name, BAD_CAST("image")))
    {
      xmlNodePtr nptr=pcur->xmlChildrenNode;
      while (pcur != NULL)
      {
        if (!xmlStrcmp(nptr->name, BAD_CAST("url")))
        {       
          urlPart = XML_GET_CONTENT(nptr->xmlChildrenNode);
          printf("url part: %s\n", urlPart);
          asprintf(&img_url, "%s%s", "https://www.bing.com", urlPart);
          break;
        }
        nptr = nptr -> next;
      }
    }
    pcur = pcur -> next;
  }

  xmlFreeDoc(pdoc);
  xmlCleanupParser();
  xmlMemoryDump();
  printf("<Parse Done!!!>\n");
}

void downloadXml()
{
  char *xml_url = "https://www.bing.com/HPImageArchive.aspx?format=xml&idx=0&n=1&mkt=en-US";
  printf("Start downloading!!!\n");
  CURL *curlXml;
  FILE *fpXml;
  CURLcode resXml;
  char *xmlName;
  asprintf(&xmlName, "%s%s%s%s%s", "/home/", getlogin(), "/BBG-Download/", datetime, "/index.xml");
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

void downloadImg()
{
  printf("<Image: Start Downloading!!!>\n");
  CURL *curlImg;
  FILE *fpImg;
  CURLcode resImg;
  asprintf(&imgName, "%s%s%s%s%s", "/home/", getlogin(), "/BBG-Download/", datetime, "/Wallpaper.jpg");
  printf("<Downloading Image!!!>\n");
  curlImg = curl_easy_init();
  if(curlImg)
  {
    fpImg = fopen(imgName, "wb");
    curl_easy_setopt(curlImg, CURLOPT_URL, img_url);
    curl_easy_setopt(curlImg, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curlImg, CURLOPT_WRITEDATA, fpImg);
    curl_easy_setopt(curlImg, CURLOPT_NOPROGRESS, 0);
    resImg = curl_easy_perform(curlImg);
    fclose(fpImg);
  }
  free(img_url);
}

int main()
{
  geTime();
  makedir();
  downloadXml();
  parseXml();
  printf("Full path: %s\n", img_url);
  downloadImg();
  free(imgName);
  return 0;
}
