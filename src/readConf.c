#include "../include/proc.h"
#include "../include/download.h"
#include "../include/color.h"

char *readConf()
{
	xmlDocPtr pdoc = NULL;
  	xmlNodePtr proot = NULL;
  	xmlNodePtr pcur = NULL;

	char *dEnv;
	char *configFile;
	asprintf(&configFile, "%s%s%s%s", "/home/", getlogin(), "/.bingbg", "/config.xml");
  
  	xmlKeepBlanksDefault(0); //Blanks may be parse as a node
  	pdoc = xmlReadFile(configFile, "UTF-8", XML_PARSE_RECOVER);

  	if (pdoc == NULL)
  	{
    	printf(RED"ERROR:cannot open config file!!!\n");
    	exit(1);
  	}

  	proot = xmlDocGetRootElement(pdoc);

  	if(proot == NULL)
  	{
    	printf(RED"ERROR: Config file is empty!!!\n");
    	exit(1);
  	}

  	pcur = proot -> xmlChildrenNode;

  	while (pcur != NULL)
  	{
    	if (!xmlStrcmp(pcur->name, BAD_CAST("DeskEnvironment")))
    	{
			xmlNodePtr nptr=pcur->xmlChildrenNode;
      		if(*(XML_GET_CONTENT(nptr)) == *("NULL"))
			{
			
				asprintf(&dEnv, "%s", setDE());
				const xmlChar *setCont = dEnv;
				xmlNodeSetContent(pcur, setCont);

				int nRel = xmlSaveFile(configFile, pdoc);
    			if (nRel != -1)
    			{
					printf("config file saved!!!\n");
    			}
				break;
			}
			else
			{
				asprintf(&dEnv, "%s", XML_GET_CONTENT(nptr));
				break;
			}
          	break;
    	}
    	pcur = pcur -> next;
  	}
  	xmlFreeDoc(pdoc);
  	xmlCleanupParser();
  	xmlMemoryDump();
	free(configFile);
	return dEnv;
}