#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <cassert>

//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ġ�
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);
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
//		printf("�ҵ��ˣ��ڵ�%d�У���%d��", x+1, y+1);
//	else
//		printf("�Ҳ���");
//}

//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

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
//	//�������
//	reverse(arr,arr+k-1);
//	//�ұ�����
//	reverse(arr+k,arr+len-1);
//	//��������
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

//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
 
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
//	//�������
//	reverse(arr, arr + k - 1);
//	//�ұ�����
//	reverse(arr + k, arr + len - 1);
//	//��������
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