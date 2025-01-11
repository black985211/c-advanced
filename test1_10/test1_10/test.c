#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//题目 1: 字符指针的基本操作
//编写一个程序，使用字符指针 char* 保存一个字符串，并通过指针访问和修改字符串中的内容。
//要求：
//定义一个字符指针指向字符串 "hello".
//使用指针访问字符串的每个字符并输出。
//将字符串的第一个字符改为 'H' 并再次输出整个字符串。

//int main()
//{
//	char arr[] = "hello";
//	char* p = arr;
//	int len = strlen(arr);
//	int i = 0;
//	for (i = 0;i < len;i++)
//	{
//		printf("%c", *(arr + i));
//	}
//	printf("\n");
//	*arr = 'H';
//	printf("%s", arr);
//	return 0;
//}


//题目 2: 数组指针与二维数组传参
//编写一个程序，通过数组指针处理二维数组的元素。
//要求：
//定义一个 3x4 的二维数组并初始化为如下内容：
//复制代码
//1  2  3  4
//5  6  7  8
//9 10 11 12
//定义一个数组指针并指向该二维数组。
//使用数组指针访问每一行的第一个元素，并输出这些值。
//编写一个函数，使用数组指针作为参数，计算二维数组中所有元素的和。
//int func(int (*arr)[4])
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0;i < 3;i++)
//	{
//		int  j = 0;
//		for (j = 0;j < 4;j++)
//		{
//			count = count +arr[i][j];
//		}
//	}
//	return count;
//}
//int main()
//{
//	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	int(*p)[4] = arr;
//	int i = 0;
//	for (i = 0;i < 3;i++)
//	{
//		printf("%d\n", p[i][0]);
//	}
//	int ret = func(arr);
//	printf("%d", ret);
//	return 0;
//
//}


//题目 3: 指针数组与字符串排序
//使用指针数组实现一个简单的字符串排序程序。
//
//要求：
//定义一个字符串数组存储以下内容：
//{ "banana", "apple", "cherry", "date" }
//使用指针数组对字符串进行排序（按字典顺序）。
//输出排序后的字符串。
//提示：可以使用标准库函数 strcmp 比较字符串。

//int compare_strings(const void* a, const void* b)
//{
//	return strcmp((*(char**)a),(*(char**)b));
//}
//int main()
//{
//	char* arr [] = {"banana", "apple", "cherry", "date"};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	printf("排序前：\n");
//	for (i = 0;i < sz;i++)
//	{
//		printf("%s ", arr[i]);
//	}
//	qsort(arr, sz, sizeof(arr[0]), compare_strings);
//	i = 0;
//	printf("\n排序后：\n");
//	for (i = 0;i < sz;i++)
//	{
//		printf("%s ", arr[i]);
//	}
//	return 0;
//}



//题目 4: 函数指针实现简单计算器
//编写一个程序，使用函数指针实现加法、减法、乘法和除法的简单计算器。
//
//要求：
//定义四个函数：add、subtract、multiply 和 divide，分别实现加法、减法、乘法和除法。
//使用一个函数指针数组保存上述函数。
//提示用户选择操作（例如输入 1 表示加法，输入 2 表示减法等），然后输入两个操作数，调用对应的函数并输出结果。
//void menu()
//{
//	printf("*******  1.  add    ********\n");
//	printf("*******  2.subtract ********\n");
//	printf("*******  3.multiply ********\n");
//	printf("*******  4. divide  ********\n");
//	printf("*******  5.  end    ********\n");
//	printf("选择操作：\n");
//}
//int add(int a, int b)
//{
//	return a + b;
//}
//int subtract(int a, int b)
//{
//	return a - b;
//}
//
//int multiply(int a, int b)
//{
//	return a * b;
//}
//int divide(int a, int b)
//{
//
//	if (b == 0)
//	{
//		printf("错误：除数不能为零\n");
//		return 0;  // 或者返回一个错误标志
//	}
//	return a / b;
//}
//
//void calc(int (*p)(int a,int b))
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = p(a, b);
//	printf("%d\n", ret);
//}
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
//			calc(subtract);
//			break;
//		case 3:
//			calc(multiply);
//			break;
//		case 4:
//			calc(divide);
//			break;
//		case 5:
//			printf("退出计算器");
//			break;
//		default:
//			printf("无效的选择，请重新输入\n");
//			break;
//		}
//	} while (input!=5);
//	return 0;
//}



//题目 5: 回调函数模拟排序
//编写一个程序，使用回调函数自定义数组的排序规则。
//
//要求：
//定义一个整型数组：int arr[] = { 5, 2, 8, 1, 3 };
//实现一个 sort 函数，接收数组、数组大小以及一个比较函数作为参数。
//定义两个比较函数：ascending（升序排序）和 descending（降序排序）。
//使用 sort 函数分别按升序和降序对数组进行排序，并输出结果。
int cmp(const void* a, const void*b)
{
	return *(int*)a - *(int*)b;
}
void swap(char* a, char* b, int size)
{
	int i = 0;
	for (i = 0;i < size;i++)
	{
		char tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}

void sort_descending(void* arr, size_t sz, size_t size, int(*cmp)(const void* a, const void* b))
{
	int i = 0;
	for (i = 0;i < sz - 1;i++)
	{
		int j = 0;
		for (j = 0;j < sz - 1 - i;j++)
		{
			if (cmp((char*)arr + j * size, (char*)arr + (j + 1) * size) < 0)
			{
				swap((char*)arr + j * size, (char*)arr + (j + 1) * size,size);
			}
		}

	}
}

void sort_ascending(void* arr, size_t sz, size_t size, int(*cmp)(const void* a, const void* b))
{
	int i = 0;
	for (i = 0;i < sz - 1;i++)
	{
		int j = 0;
		for (j = 0;j < sz - 1 - i;j++)
		{
			if (cmp( (char*)arr+j*size,(char *)arr+(j+1)*size ) > 0)
			{
				swap((char*)arr + j * size, (char*)arr + (j + 1) *size,size);
			}
		}

	}
}
int main()
{
	int arr[]= { 5, 2, 8, 1, 3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort_ascending(arr, sz, sizeof(arr[0]), cmp);
	
	printf("升序：\n");
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	sort_descending(arr, sz, sizeof(arr[0]), cmp);
	printf("降序：\n");
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}

}