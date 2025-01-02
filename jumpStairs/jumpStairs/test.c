#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//青蛙跳台阶  青蛙每次可跳一个台阶或两个台阶
int jumpStair(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else
		return jumpStair(n - 1) + jumpStair(n - 2);
}


int main()
{
	int n = 0;
	printf("共有多少台阶：");
	scanf("%d", &n);
	int ret =jumpStair(n);
	printf("共有%d种跳法", ret);
	return 0;

}