#include "../include/proc.h"
#include "../include/color.h"

char *geTime()
{
	static char datetime[200];
  	time_t now;
  	struct tm *tm_now;
  	printf(NONE"[%d]Getting datetime...\n", &now);

  	time(&now);
  	tm_now = localtime(&now);
  	strftime(datetime, 200, "%m-%d-%Y", tm_now);

  	printf(YELLOW"[%d]Successful!!!", &now);
  	printf(YELLOW"----------Now: %s\n", datetime);
  	return datetime;
}