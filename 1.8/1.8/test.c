#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	char a = -1;
//	//10000000 00000000 00000000 00000001
//	//11111111 11111111 11111111 11111110
//	//11111111 11111111 11111111 11111111
//	signed char b = -1;
//	//11111111 11111111 11111111 11111111
//	unsigned char c = -1;
//	//11111111 11111111 11111111 11111111
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}


//int main()
//{
//	char a = -128;
//	//10000000 00000000 00000000 10000000
//	//11111111 11111111 11111111 01111111
//	//11111111 11111111 11111111 10000000
//	//10000000
//	printf("%u\n", a);  
//	return 0;
//}


//int main()
//{
//	char a = 128;
//	//00000000 00000000 00000000 10000000
//	//10000000
//	printf("%u\n", a); 
//	return 0;
//}
//int main()
//{
//	int i = -20;
//	//10000000 00000000 00000000 00010100
//	//11111111 11111111 11111111 11101011
//	//11111111 11111111 11111111 11101100
//	
//	unsigned int j = 10;
//	//00000000 00000000 00000000 00001010
//	
//	printf("%d\n", i + j);
//	//11111111 11111111 11111111 11101110
//
//
//	//按照补码的形式进行运算，最后格式化成为有符号整数
//	return 0;
//}


//题目 1: 字符指针的基本操作
//编写一个程序，使用字符指针 char* 保存一个字符串，并通过指针访问和修改字符串中的内容。
//要求：
//定义一个字符指针指向字符串 "hello".
//使用指针访问字符串的每个字符并输出。
//将字符串的第一个字符改为 'H' 并再次输出整个字符串。


//#include<string.h>
//int main()
//{
//	char arr[] = "hello";
//	char* p = arr;
//	int len = strlen(arr);
//	printf("%s\n", p);
//	int i = 0;
//	for (i = 0;i < len;i++)
//	{
//		printf("%c", p[i]);
//	}
//	printf("\n");
//	p[0] = 'H';
//	for (i = 0;i < len;i++)
//	{
//		printf("%c", p[i]);
//	}
//	printf("\n");
//	
//}



//题目 2: 数组指针与二维数组传参
//编写一个程序，通过数组指针处理二维数组的元素。
//要求：
//定义一个 3x4 的二维数组并初始化为如下内容：
//1  2  3  4
//5  6  7  8
//9 10 11 12
//定义一个数组指针并指向该二维数组。
//使用数组指针访问每一行的第一个元素，并输出这些值。
//编写一个函数，使用数组指针作为参数，计算二维数组中所有元素的和。

int main()
{
	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	int (*p)[4] = arr;
	int i = 0;
	for (i = 0;i < 3;i++)
	{
		int j = 0;
		for (j = 0;j < 4;j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	return 0;
}



