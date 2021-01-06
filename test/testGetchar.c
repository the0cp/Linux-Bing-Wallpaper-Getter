#include <stdio.h>

int main()
{
	int c;
	while((c = getchar()) != '\t')
	{
		printf("%d\n", c);
	}
	return 0;
}