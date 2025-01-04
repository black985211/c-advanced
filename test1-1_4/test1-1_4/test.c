#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//判断大小端
//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (1 == *p)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}

//int main()
//{
//	char a = -128;
//	printf("%u\n", a);
//	return 0;
//}


//int main()
//{
//	char a = 128;
//	printf("%u\n", a);
//	return 0;
//}

//int main()
//{
//	int i = -20;
//	//10000000 00000000 00000000 00010100
//	//11111111 11111111 11111111 11101011
//	//11111111 11111111 11111111 11101100  补码
//	unsigned int j = 10;
//	printf("%d\n", i + j);
//	//按照补码的形式进行运算，最后格式化成为有符号整数
//}

//int main()
//{
//	unsigned int i;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//	}
//	return 0;
//}

//int main()
//{
//	char a[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%d", strlen(a));
//	return 0;
//}

unsigned char i = 0;
int main()
{
	for (i = 0;i <= 255;i++)
	{
		printf("hello world\n");
	}
	return 0;
}