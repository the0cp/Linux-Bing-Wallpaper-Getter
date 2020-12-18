#define _GNU_SOURCE


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <libxml/tree.h>
#include <libxml/parser.h>

extern char *geTime();
extern void usage();
extern void conf(char *USRNAME);
extern char *readConf();
extern char *setDE();
extern void excu(char *TIME_EX, char *USRNAME, char *DE);
extern void makeDir(char *TIME_MD, char *USRNAME);
extern char *parseXml(char *TIME_PX, char *USRNAME);


