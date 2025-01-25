#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int cmp_arr(const void *a,const void * b)
//{
//	return ((*(int*)b) - (*(int*)a));
//}
//int main()
//{
//	int arr[] = { 2,9,8,1,4,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_arr);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//typedef struct Stu
//{
//	int age;
//	char name[100];
//}stu;
//int stu_age_cmp(const void* a, const void* b)
//{
//	return ((*(stu*)a).age - (*(stu*)b).age);
//}
//int main()
//{
//	stu arr[] = { {10,"yanggang"},{20,"zhangsan"},{5,"lisi"} };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), stu_age_cmp);
//	int i = 0;
//	for (i = 0; i < sz;i++)
//	{
//		printf("%d,%s\n", arr[i].age, arr[i].name);
//	}
//	return 0;
//}

//ÊµÏÖqsort
int cmp_int(const void* e1, const void* e2)
{
	return *((int*)e1) - *((int*)e2);
}
void swap(char* a, char* b, size_t size)
{
	int i = 0;
	for (i = 0;i < size;i++)
	{
		char temp = *a;
		*a = *b;
		*b = temp;
		a++;
		b++;
	}
}
void my_qsort(void* base, size_t num, size_t size, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0;i < num - 1;i++)
	{
		int j = 0;
		for (j = 0;j < num - 1 - i;j++)
		{
			if (cmp((char*)base+j*size,(char * )base+(j+1)*size) > 0)
			{
				swap((char*)base + j * size, (char*)base +(j+1) * size, size);
			}
		}
	}
}
int main()
{
	int arr[] = { 2,5,3,7,5,9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	my_qsort(arr, sz, sizeof(arr[0]), cmp_int);

	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
}