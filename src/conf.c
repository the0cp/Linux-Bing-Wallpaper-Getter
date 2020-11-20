#include "../include/proc.h"
#include "../include/download.h"
#include "../include/color.h"

void conf(char *USRNAME)
{
	char *conFolder;
	asprintf(&conFolder, "%s%s%s", "/home/", USRNAME, "/.bingbg");
	printf(NONE"Creating .bingbg");

	if(access(conFolder, 0) == -1)
	{
	mkdir(conFolder, S_IRWXO | S_IRWXU);
    printf(YELLOW"[%d]", *conFolder);
    printf(YELLOW"Successful!!!\n");
	}
	else
  	{
    printf(CYAN"[%d]", *conFolder);
    printf(CYAN"Folder is already created!!\n");
  	}

	asprintf(&conFolder, "%s%s%s%s", "/home/", USRNAME, "/.bingbg", "/config.xml");

	if(access(conFolder, 0) == -1)
	{
		xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
    	xmlNodePtr root_node = xmlNewNode(NULL, BAD_CAST"root");
    	xmlDocSetRootElement(doc,root_node);

    	xmlNewTextChild(root_node, NULL, BAD_CAST "DeskEnvironment", BAD_CAST "NULL");

    	int nRel = xmlSaveFile(conFolder, doc);
    	if (nRel != -1)
    	{
       		printf(YELLOW"config file successfully created!!!\n");
    	}
    	xmlFreeDoc(doc);
		free(conFolder);
	}
	else
	{
		free(conFolder);
	}
}