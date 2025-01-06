#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void menu()
//{
//	printf("1.add\n");
//	printf("2.sub\n");
//	printf("3.mul\n");
//	printf("4.dov\n");
//	printf("5.exit\n");
//}
//void calc(int (*p) (int,int))
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = p(a, b);
//	printf("%d\n", ret);
//}
//int sub(int a,int b)
//{
//	return a - b;
//}
//int mul(int a, int b)
//{
//	return a*b;
//}
//int div(int a, int b)
//{
//	if (b == 0)
//	{
//		printf("错误：除数不能为零\n");
//		return 0;  // 或者返回一个错误标志
//	}
//	return a / b;
//}
//
//int add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{ 
//		case 1:
//			calc(add);
//			break;
//		case 2:
//			calc(sub);
//			break;
//		case 3:
//			calc(mul);
//			break;
//		case 4:
//			calc(div);
//			break;
//		case 5:
//			printf("退出计算\n");
//			break;
//		default:
//			printf("输入错误请重新输入：\n");
//			break;
//		}
//	} while (input!=5);
//	return 0;
//}

//void sort(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz - 1;i++)
//	{
//		int j = 0;
//		for (j = 0;j < sz - 1 - i;j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j]=tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 3,4,2,9,8,6,7};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	sort(arr, sz);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	
//	return 0;
//}


//int cmp(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//int main()
//{
//	int arr[] = { 3,4,2,9,8,6,7 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sizeof(arr), sizeof(arr[0]), cmp);
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//	return 0;
//}

//struct stu
//{
//	int age;
//	char name[100];
//};
//
//int cmp1(const void* a, const void* b)
//{
//	return ((struct stu*)a)->age - ((struct stu*)b)->age;
//}
//int cmp2(const void* a, const void* b)
//{
//	return strcmp(((struct stu*)a)->name ,((struct stu*)b)->name);
//}
//int main()
//{
//	struct stu s[] = { {10,"yanggang"},{20,"lisi"},{6,"zhangsan"} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//qsort(s, sz, sizeof(s[0]), cmp1);
//	qsort(s, sz, sizeof(s[0]), cmp2);
//
//
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d,%s", s[i].age, s[i].name);
//		printf("\n");
//	}
//	return 0;
//}
struct stu
{
	char name[100];
	int age;
};
int cmp_int(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int cmp_struct(const void* a, const void* b)
{
    return strcmp(((struct stu*)a)->name, ((struct stu*)b)->name);
}
void swap(char* p1,char*p2,int size)
{
	int i = 0;
	for (i = 0;i < size;i++)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;
	}
}
void my_qsort(void* base, size_t num, size_t size, int(*cmp)(const void* a, const void* b))
{
		int i = 0;
		
		for (i = 0;i < num - 1;i++)
		{
			int j = 0;
			for (j = 0;j < num - 1 - i;j++)
			{
				if (cmp( (char *)base+j*size, (char*)base + (j+1 )* size )> 0)
				{
					swap((char*)base + j * size, (char*)base + (j + 1) * size,size);
				}
			}
		}
}

void test1()
{
	int arr[] = { 3,4,2,9,8,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
}
void test2()
{
	struct stu s[] = { {"zhangsan",10},{"lisi",8},{"wangwu",3 } };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), cmp_struct);
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%s,%d\n", (s+i)->name, (s+i)->age);
	}
}

int main()
{
	test1();
	printf("\n");
	test2();
	return 0;
}