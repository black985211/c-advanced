#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	FILE *pf = fopen("text.txt", "w");
	if (NULL == pf)
	{
		perror("fopen");
		return 1;
	}
	char ch = 0;
	for (ch = 'a';ch <= 'z';ch++)
	{
		fputc(ch, pf);
	}

	fclose(pf);
	pf == NULL;
	return 0;


}