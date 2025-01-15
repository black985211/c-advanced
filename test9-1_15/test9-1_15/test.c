#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//enum Sex
//{
//	male,
//	female,
//	secrect
//};
//
//int main()
//{
//	enum Sex sex = female;
//	printf("%d", sex);
//	return 0;
//}


#include<stdlib.h>
#include<string.h>
#include <errno.h>
int main()
{
	int* p = (int*)malloc(10*sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return 1;
	}
	int i = 0;
	for (i = 0;i < 10;i++)
	{
		*(p + i) = i + 1;
	}
	for (i = 0;i < 10;i++)
	{
		printf("%d ", *(p + i));
	}
	int* temp = (int*)realloc(p, 20 * sizeof(int));
	if (temp == NULL)
	{
		free(p);
		return 1;
	}
	p = temp;
	for (i = 10;i < 20;i++)
	{
		*(p + i) = i + 1;
	}
	for (i = 0;i < 20;i++)
	{
		printf("%d ", *(p + i));
	}
	free(p);

	return 0;
}


