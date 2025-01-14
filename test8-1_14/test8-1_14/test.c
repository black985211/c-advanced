#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#pragma pacl(1)
struct S1
{
	char c1;
	int i;
	char c2;
};
#pragma pack()

int main()
{
	return 0;
}
