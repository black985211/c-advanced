#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>

//int main()
//{
//	int ret = islower('a');
//	printf("%d", ret);
//	return 0;
//}
//void* my_memcpy(void* dest, void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest && src);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
//	int arr2[20] = {0};
//	my_memcpy(arr2, arr1, 20);
//	return 0;
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//typedef struct Stu stu;
//int main()
//{
//	stu s1;
//	return 0;
//}

typedef struct stu
{
	int age;
	//struct stu* next;
	char name[20];
}stu;

struct S
{
	int num;
	char ch[10];
	stu s1;
	float d;
};
int main()
{
	/*stu n1;
	stu n2;
	n1.next = &n2;*/

	struct S S = { 10,"shuxue",{10,"yanggang"},1.75f };
	printf("%d %s %d %s %f", S.num, S.ch, S.s1.age,S.s1.name,S.d);
	return 0;
}