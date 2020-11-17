#include "../include/proc.h"
#include "../include/download.h"
#include "../include/color.h"

char *parseXml(char *TIME_PX, char *USRNAME)
{
	char *img_url;
	char *urlPart;
  	char *xmlName;
  	asprintf(&xmlName, "%s%s%s%s%s", "/home/", USRNAME, "/BBG-Download/", TIME_PX, "/index.xml");
  	xmlDocPtr pdoc = NULL;
  	xmlNodePtr proot = NULL;
  	xmlNodePtr pcur = NULL;
  
  	xmlKeepBlanksDefault(0); //Blanks may be parse as a node
  	pdoc = xmlReadFile(xmlName, "UTF-8", XML_PARSE_RECOVER);

  	if (pdoc == NULL)
  	{
    	printf(RED"ERROR:cannot open xml!!!\n");
    	exit(1);
  	}

  	proot = xmlDocGetRootElement(pdoc);

  	if(proot == NULL)
  	{
    	printf(RED"ERROR: Xml is empty!!!\n");
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
          			printf(YELLOW UNDERLINE"URL part: %s", urlPart);
					printf(NONE"\n");
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
  	printf(L_GREEN"<Parse Done!!!>\n");
	printf(YELLOW"Full path: %s\n", img_url);	
	return img_url;
	
}
