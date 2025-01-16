#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}



//struct s
//{
//	int a;
//	char arr[];
//};
//int main()
//{
//	struct s* p = (struct s *)malloc(sizeof(struct s)+ 10 * sizeof(char));
//	if (p == NULL)
//	{
//		return 1;
//	}
//	struct s* ptr = (struct s*)realloc(p, sizeof(struct s) + 20 * sizeof(char));
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	else
//	{
//		perror("realloc");
//		return 1;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

struct S
{
	int n;
	char* arr;
};
int main()
{
	struct S* p = (struct S*)malloc(sizeof(struct S));
	if (p == NULL)
	{
		perror("malloc");
		return 1;
	}
	p->arr = (char*)malloc(sizeof(char) * 10);
	if (p->arr == NULL)
	{
		return 1;
	}
	free(p->arr);
	p->arr = NULL;
	free(p);
	p = NULL;
	return 0;
}