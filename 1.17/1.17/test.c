#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//1. malloc和free的基本使用
//编写一个程序，使用malloc为一个整数数组分配内存，然后使用free释放该内存。请确保在释放内存之前，数组的内容已经被打印出来。

//int main()
//{
//	int* arr = (int*)malloc(10 * sizeof(int));
//	if (arr == NULL)
//	{
//		perror("arr:NULL");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		arr[i] = i+1;
//	}
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}

//2. 动态数组实现
//创建一个程序，动态分配一个整数数组的内存。程序要求用户输入数组的大小，然后输入相应数量的整数，最后打印出这些整数并释放内存。

//int main()
//{
//	int sz = 0;
//	printf("请输入数组的大小：");
//	scanf("%d", &sz);
//	int* arr = (int*)malloc(sz * sizeof(int));
//	if (arr == NULL)
//	{
//		perror("arr:NULL");
//		return 1;
//
//	}
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}

//3. 内存泄漏检查
//编写一个函数，分配内存给一个字符串数组，并在函数结束时没有释放该内存。试着分析程序，看看是否会发生内存泄漏，并如何修复。


//void memory_leak_demo() {
//    // 动态分配内存给一个字符数组
//    char* arr = (char*)malloc(10 * sizeof(char));
//    if (arr == NULL) {
//        perror("Memory allocation failed");
//        return;
//    }
//
//    // 模拟对arr的使用，例如存储一些字符
//    arr[0] = 'A';
//    arr[1] = 'B';
//    // ... 可以继续使用这个数组
//
//    // 演示没有释放内存的情况：程序结束时 arr 没有被 free
//    // 没有调用 free(arr)，这里就发生了内存泄漏
//    // 程序结束时会返回 arr 指向的内存区域无法被回收
//}
//
//int main() {
//    memory_leak_demo(); // 演示内存泄漏
//
//    // 为了修复内存泄漏，我们应该手动释放内存
//    // 解决内存泄漏：在函数结束前调用 free 释放内存
//    // memory_leak_demo(); -> 如果在函数末尾释放内存，就不会有内存泄漏
//
//    return 0;
//}


//4. 指针的指向
//假设你有一个指针指向一个动态分配的二维数组，如何正确访问和释放内存？
//int** matrix;
//请编写代码实现以下功能：
//为matrix动态分配内存，用于存储一个n x m的二维数组。
//填充数组并打印。
//释放分配的内存。

//int main()
//{
//	int n = 3;
//	int m = 3;
//	int** matrix = (int**)malloc(n * sizeof(int*));
//	if (matrix == NULL) {
//		printf("内存分配失败！\n");
//		return 1; // 如果分配失败，退出程序
//	}
//	int i = 0;
//	for(i = 0;i < n;i++)
//	{
//		matrix[i] = (int*)malloc(m * sizeof(int));
//	}
//	for (i = 0; i < n; i++) {
//		free(matrix[i]); // 释放每一行的内存
//		matrix[i] = NULL; // 将行指针置为NULL
//	}
//	free(matrix); // 释放行指针数组的内存
//	matrix = NULL; // 将matrix指针置为NULL
//
//	return 0;
//}

//5. 内存扩展
//编写一个程序，先为一个整数数组分配内存，然后要求用户输入数据。
//接着，如果用户输入的数据量超过原来分配的内存大小，使用realloc扩展内存，并继续输入数据。最后打印数组的内容。

//int main()
//{
//    int capacity = 3;
//    int* arr = (int*)malloc(capacity * sizeof(int)); // 初始化内存
//    if (arr == NULL)
//    {
//        printf("Memory allocation failed\n");
//        return 1;
//    }
//
//    int input = 0;
//    int i = 0;
//
//    while (1)
//    {
//        // 输入数字
//        printf("请输入一个整数：");
//        scanf("%d", &input);
//
//        // 存储输入的值
//        arr[i] = input;
//        i++;
//
//        // 判断是否需要扩容
//        if (i >= capacity)
//        {
//            // 扩容：将容量翻倍
//            int* ptr = (int*)realloc(arr, 2 * capacity * sizeof(int));
//            if (ptr == NULL)
//            {
//                printf("Memory reallocation failed\n");
//                free(arr);
//                return 1;
//            }
//            arr = ptr;
//            capacity *= 2;  // 更新容量为翻倍后的值
//            printf("扩容成功！新的容量为 %d 个整数。\n", capacity);
//
//            
//           
//        }
//
//        // 如果输入达到最大数量（例如 10），退出循环
//        if (i == 10)
//        {
//            break;
//        }
//    }
//
//    // 打印数组内容
//    printf("输入的数组内容：");
//    for (int j = 0; j < i; j++)
//    {
//        printf("%d ", arr[j]);
//    }
//    printf("\n");
//
//    // 释放内存
//    free(arr);
//    arr = NULL;
//
//    return 0;
//}

//6. 使用calloc
//写一个程序，使用calloc为一个数组分配内存。
//与使用malloc的不同之处在于，calloc会将所有内存初始化为零。请打印数组内容，并释放内存。
int main()
{
    int* p = (int*)calloc(3,sizeof(int));
    if (p == NULL) {
        printf("内存分配失败！\n");
        return 1;
    }
    int i = 0;
    for(i = 0;i < 3;i++)
    {
        printf("%d ", p[i]);
    }
    free(p);
    p = NULL;
    return 0;
}

