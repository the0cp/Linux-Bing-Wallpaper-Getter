#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

char *test_1;

char *asp()
{
	asprintf(&test_1, "test1", " test2");
	return test_1;
}
int main(int argc, char **argv)
{
	char *test_2 = asp();
	printf("test_1:%s\n",test_1);
	printf("test_2:%s\n",test_2);
	free(test_2);
	printf("test_1:%s\n",test_1);
	printf("test_2:%s\n",test_2);
	return 0;
}
