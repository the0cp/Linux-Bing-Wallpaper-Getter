#include "headers/proc.h"
#include "headers/download.h"

char *parseXml()
{
	char *img_url;
	char *urlPart;
  	char *xmlName;
  	asprintf(&xmlName, "%s%s%s%s%s", "/home/", getlogin(), "/BBG-Download/", geTime(), "/index.xml");
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
	printf("Full path: %s\n", img_url);
	return img_url;
}
