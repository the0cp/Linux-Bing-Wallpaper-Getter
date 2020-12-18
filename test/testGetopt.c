#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
   int ch;
   opterr = 0;
   while((ch = getopt(argc, argv, "a:bcdhe")) != -1)
   if(ch == 'a')
   {
	   printf("a\n");
   }
   else if(ch == 'b')
   {
	   printf("b\n");
   }
   else if(ch == 'h')
   {
	   printf("h\n");
   }
   else
   {
	   printf("(null)");
   }
   printf("optopt +%c\n", optopt);
}