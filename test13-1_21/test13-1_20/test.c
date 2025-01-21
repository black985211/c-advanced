#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	printf("hehe");
//	return 0;
//}

//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	//printf("%d\n", __STDC__);
//
//	return 0;
//}



//#define do_forever for(;;)
//int main()
//{
//	do_forever;
//	return 0;
//}

//#define SQUARE(X) (X) *(X)
//
//int main()
//{
//	printf("%d\n", SQUARE(5+1));
//	
//	return 0;
//}

#define CAT(x,y) x##y
int main()
{
	int yang2003 = 614;
	printf("%d\n", CAT(yang, 2003));
	return 0;
}
