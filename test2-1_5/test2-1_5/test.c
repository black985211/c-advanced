#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	const char* p = "abcdef";
//	printf("%s ",p);
//	return 0;
//}

//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	const char* str3 = "hello bit.";
//	const char* str4 = "hello bit.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	return 0;
//}


//int main()
//{
//	char arr[5];
//	char (*pa)[5] = &arr;
//;	return 0;
//}

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6 };
//	int (*pa)[10] = &arr;
//	int i = 0;
//	for (i = 0;i < 6;i++)
//	{
//		printf("%d ", (*pa)[i]);
//	}
//	return 0;
//}
//void print(int (*p)[3], int row)
//{
//	int i = 0;
//	for (i = 0;i < row;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 3;j++)
//		{
//			printf("%d ", p[i][j]);
//		}
//	}
//}
//int main()
//{
//	int arr[2][3] = { {1,2,3},{4,5,6} };
//	print(arr, 2);
//	return 0;
//}

//int main()
//{
//	int arr[5] = { 10, 20, 30, 40, 50 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0;i < 5;i++)
//	{
//		printf("%d ", *(p + i));
//		
//	}
//	printf("\n");
//	for (i = 0;i < 5;i++)
//	{
//		
//		printf("%d ", p[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr[2][3] = {{1, 2, 3},{4, 5, 6}};
//	int (*p)[3] = arr;
//	int i = 0;
//	for (i = 0;i < 2;i++)
//	{
//		int j = 0;
//		for (j = 0;j < 3;j++)
//		{
//			printf("%d ", p[i][j]);
//		}
//		printf("\n");
//	}
//}

//int main()
//{
//    int arr[3][4] = {
//    {1, 2, 3, 4},
//    {5, 6, 7, 8},
//    {9, 10, 11, 12}
//    };
//    int (*p)[4] = arr;
//    printf("%d \n", *(*(p+0)+1));
//    printf("%d \n", *(*(p + 1) + 2));
//    int i = 0;
//    for (i = 0;i < 3;i++)
//    {
//        int j = 0;
//        for (j = 0;j < 4;j++)
//        {
//            printf("%d ", *(*(p + i) + j));
//        }
//        printf("\n");
//    }
//    for (i = 0;i < 3;i++)
//    {
//        int j = 0;
//        for (j = 0;j < 4;j++)
//        {
//            printf("%d ", p[i][j]);
//        }
//        printf("\n");
//    }
//	return 0;
//}


#include <stdio.h>

// 定义一个返回 int 类型的函数
int add(int a, int b) {
    return a + b;
}

int main() {
    // 声明一个指向 add 函数的指针
    int (*func_ptr)(int, int) = add;

    // 通过函数指针调用 add 函数
    int result = func_ptr(3, 4);  // 等价于 add(3, 4)
    printf("Result: %d\n", result);  // 输出 Result: 7

    return 0;
}
