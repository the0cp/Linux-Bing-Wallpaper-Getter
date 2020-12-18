#include<stdio.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
	//int i;
	 int count = 1;
    if(argc==1)
    {
		printf("no arg\n");
    }
    else
    {
		//for(count = 1; count < argc; count++)
        printf("%s:\n",*++argv);
        if(*++argv == "jh")
		{
			printf("arg \"h\"\n");
		}
		else if(*++argv == "jg")
		{
			printf("arg \"g\"\n");
		}
        else
		{
			printf("null arg\n");
		}
    }
	/*
	for(i = 0; i < argc; i++)
	{
		printf( "nArgument argv[%d] = %s \n",i, argv[i]);
	} 
	*/
    return 0;
}