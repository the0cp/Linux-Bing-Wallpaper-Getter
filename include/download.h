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


extern void downloadXml(char *TIME_XML);
extern void downloadImg(char *TIME_IMG);