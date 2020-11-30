#include<stdio.h>
int main()
{
	FILE *fp = NULL;
	char *data;
	fp = popen("echo hello world", "r");
	if (fp == NULL)
	{
		printf("popen error!\n");
		return 1;
	}
	while (fgets(data, sizeof(data), fp) != NULL)
	{
		printf("%s", data);
	}
	pclose(fp);
	return 0;
}