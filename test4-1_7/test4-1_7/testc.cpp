#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <cassert>

//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的。
//请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);
//int Find(int arr[3][3], int* px, int* py, int k)
//{
//	int x = 0;
//	int y = *py - 1;
//	int flag = 0;
//	while (x<*px&&y>=0)
//	{
//		if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1;
//			break;
//		}
//	}
//		return 0;	
//}
//int main()
//{
//	int arr[3][3] =
//	{
//		{1,2,3},
//		{4,5,6},
//		{7,8,9}
//	};
//
//	int k = 7;
//	int x = 3;
//	int y = 3;
//	int ret =Find(arr,&x,&y,k);
//	if (ret == 1)
//		printf("找到了！在第%d行，第%d列", x+1, y+1);
//	else
//		printf("找不到");
//}

//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//void left_move(char arr[], int k)
//{
//	int i = 0;
//	int len = strlen(arr);
//	k %= len;
//	for (i = 0;i < k;i++)
//	{
//		char tmp = arr[0];
//		int j = 0;
//		for (j = 0;j < len - 1;j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[len - 1] = tmp;
//	}
//	
//}
//void reverse(char *left,char*right)
//{
//	assert(left);
//	assert(right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_move(char arr[], int k)
//{
//	
//	int len = strlen(arr);
//	k %= len;
//	//左边逆序
//	reverse(arr,arr+k-1);
//	//右边逆序
//	reverse(arr+k,arr+len-1);
//	//整体逆序
//	reverse(arr, arr + len-1);
//
//
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 2;
//	left_move(arr, k);
//	printf("%s\n", arr);
//	return 0;
//}

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
 
//void reverse(char *left,char*right)
//{
//	assert(left);
//	assert(right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_move(char arr[], int k)
//{
//
//	int len = strlen(arr);
//	k %= len;
//	//左边逆序
//	reverse(arr, arr + k - 1);
//	//右边逆序
//	reverse(arr + k, arr + len - 1);
//	//整体逆序
//	reverse(arr, arr + len - 1);
//}
//int is_left_move(char s1[],char s2[])
//{
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//	if (len1 != len2)
//		return 0;
//	int i = 0;
//	for (i = 0;i < len1 - 1;i++)
//	{
//		left_move(s1, 1);
//		if (strcmp(s1, s2) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
int is_left_move(char s1[], char s2[])
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2)
		return 0;
	strncat(s1, s1, len1);
	if (strstr(s1, s2) != NULL)
		return 1;
	else
		return 0;
}
int main()
{
	char s1[30] = "AABCD";
	char s2[] = "BCDAA";
	int ret = is_left_move(s1,s2);
	if (ret == 1)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
	return 0;
}