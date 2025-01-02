#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//extern int  a;
//int main()
//{
//	printf("%d",a);
//	return 0;
//}
//enum Color
//{
//	RED,
//	GREEN,
//	BLUE
//};
//int main()
//{
//	enum Color c = BLUE;
//	printf("%d\n",RED);
//	printf("%d\n", BLUE);
//	printf("%d\n", GREEN);
//

char ch1[] = { 'a','b','c','\0'};
char ch2[] = "abc";

int main()
{
	/*printf("%s\n", ch1);
	printf("%s\n", ch2);
	int len2 = strlen(ch2);
	int len1 = strlen(ch1);

	printf("%d\n", len2);
	printf("%d\n", len1);*/
	/*int a = 10;
	printf("%d", a);*/
	int input = 0;
	printf("加入比特，你要好好学习(0/1)? ");
	scanf("%d", &input);
	if (input == 0)
		printf("good offer");
	else if (input == 1)
		printf("go home ");
	else
		printf("error");



	return 0;
}