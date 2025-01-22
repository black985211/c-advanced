#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int Max(int a, int b)
//{
//	return (a > b ? a : b);
//}
//int main()
//{
//	int a = 10;
//	int b = 11;
//	int m = Max(a++, b++);
//	printf("m=%d a=%d b=%d", m, a, b);
//	return 0;
//
//}



//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	//int* p1 = (int*)malloc(4 * sizeof(int));
//	int* p2 = MALLOC(4, int);
//	if (p2 == NULL)
//	{
//		perror("p2:NULL");
//		return 1;
//	}
//	free(p2);
//	p2 = NULL;
//	return 0;
//}

//#define M 5
//
//int main()
//{
//#if M==1
//	printf("hehe\n");
//#elif M==5
//	printf("haha\n");
//#else
//	printf("heihei");
//#endif
//	return 0;
//}


//#include<stddef.h>
//
//struct S
//{
//	char c1;
//	int i;
//	char c2;
//
//};
//#define OFFSETOF(type,member)  (size_t)&(((type*)0)->member)
//int main()
//{
//	printf("%d\n", offsetof(struct S, c1));
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, c2));
//	printf("%d\n", OFFSETOF(struct S, c1));
//	printf("%d\n", OFFSETOF(struct S, i));
//	printf("%d\n", OFFSETOF(struct S, c2));
//	return 0;
//}


#define SWAP(x) ((((x) & 0x55555555) << 1) + (((x) & 0xaaaaaaaa) >> 1))

int main()
{
	int a = 11;//1011
	a = SWAP(a);
	//1011&0101=0001 保留奇数位  0010
	//1011&1010=1010 保留偶数位  0101 
	//0010+0101=0111=7
	printf("%d\n", a);
	return 0;
}