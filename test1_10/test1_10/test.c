#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//��Ŀ 1: �ַ�ָ��Ļ�������
//��дһ������ʹ���ַ�ָ�� char* ����һ���ַ�������ͨ��ָ����ʺ��޸��ַ����е����ݡ�
//Ҫ��
//����һ���ַ�ָ��ָ���ַ��� "hello".
//ʹ��ָ������ַ�����ÿ���ַ��������
//���ַ����ĵ�һ���ַ���Ϊ 'H' ���ٴ���������ַ�����

//int main()
//{
//	char arr[] = "hello";
//	char* p = arr;
//	int len = strlen(arr);
//	int i = 0;
//	for (i = 0;i < len;i++)
//	{
//		printf("%c", *(arr + i));
//	}
//	printf("\n");
//	*arr = 'H';
//	printf("%s", arr);
//	return 0;
//}


//��Ŀ 2: ����ָ�����ά���鴫��
//��дһ������ͨ������ָ�봦���ά�����Ԫ�ء�
//Ҫ��
//����һ�� 3x4 �Ķ�ά���鲢��ʼ��Ϊ�������ݣ�
//���ƴ���
//1  2  3  4
//5  6  7  8
//9 10 11 12
//����һ������ָ�벢ָ��ö�ά���顣
//ʹ������ָ�����ÿһ�еĵ�һ��Ԫ�أ��������Щֵ��
//��дһ��������ʹ������ָ����Ϊ�����������ά����������Ԫ�صĺ͡�
//int func(int (*arr)[4])
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0;i < 3;i++)
//	{
//		int  j = 0;
//		for (j = 0;j < 4;j++)
//		{
//			count = count +arr[i][j];
//		}
//	}
//	return count;
//}
//int main()
//{
//	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	int(*p)[4] = arr;
//	int i = 0;
//	for (i = 0;i < 3;i++)
//	{
//		printf("%d\n", p[i][0]);
//	}
//	int ret = func(arr);
//	printf("%d", ret);
//	return 0;
//
//}


//��Ŀ 3: ָ���������ַ�������
//ʹ��ָ������ʵ��һ���򵥵��ַ����������
//
//Ҫ��
//����һ���ַ�������洢�������ݣ�
//{ "banana", "apple", "cherry", "date" }
//ʹ��ָ��������ַ����������򣨰��ֵ�˳�򣩡�
//����������ַ�����
//��ʾ������ʹ�ñ�׼�⺯�� strcmp �Ƚ��ַ�����

//int compare_strings(const void* a, const void* b)
//{
//	return strcmp((*(char**)a),(*(char**)b));
//}
//int main()
//{
//	char* arr [] = {"banana", "apple", "cherry", "date"};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	printf("����ǰ��\n");
//	for (i = 0;i < sz;i++)
//	{
//		printf("%s ", arr[i]);
//	}
//	qsort(arr, sz, sizeof(arr[0]), compare_strings);
//	i = 0;
//	printf("\n�����\n");
//	for (i = 0;i < sz;i++)
//	{
//		printf("%s ", arr[i]);
//	}
//	return 0;
//}



//��Ŀ 4: ����ָ��ʵ�ּ򵥼�����
//��дһ������ʹ�ú���ָ��ʵ�ּӷ����������˷��ͳ����ļ򵥼�������
//
//Ҫ��
//�����ĸ�������add��subtract��multiply �� divide���ֱ�ʵ�ּӷ����������˷��ͳ�����
//ʹ��һ������ָ�����鱣������������
//��ʾ�û�ѡ��������������� 1 ��ʾ�ӷ������� 2 ��ʾ�����ȣ���Ȼ���������������������ö�Ӧ�ĺ�������������
//void menu()
//{
//	printf("*******  1.  add    ********\n");
//	printf("*******  2.subtract ********\n");
//	printf("*******  3.multiply ********\n");
//	printf("*******  4. divide  ********\n");
//	printf("*******  5.  end    ********\n");
//	printf("ѡ�������\n");
//}
//int add(int a, int b)
//{
//	return a + b;
//}
//int subtract(int a, int b)
//{
//	return a - b;
//}
//
//int multiply(int a, int b)
//{
//	return a * b;
//}
//int divide(int a, int b)
//{
//
//	if (b == 0)
//	{
//		printf("���󣺳�������Ϊ��\n");
//		return 0;  // ���߷���һ�������־
//	}
//	return a / b;
//}
//
//void calc(int (*p)(int a,int b))
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int ret = p(a, b);
//	printf("%d\n", ret);
//}
//int main()
//{
//	int input = 0;
//	do
//	{
//		menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			calc(add);
//			break;
//		case 2:
//			calc(subtract);
//			break;
//		case 3:
//			calc(multiply);
//			break;
//		case 4:
//			calc(divide);
//			break;
//		case 5:
//			printf("�˳�������");
//			break;
//		default:
//			printf("��Ч��ѡ������������\n");
//			break;
//		}
//	} while (input!=5);
//	return 0;
//}



//��Ŀ 5: �ص�����ģ������
//��дһ������ʹ�ûص������Զ���������������
//
//Ҫ��
//����һ���������飺int arr[] = { 5, 2, 8, 1, 3 };
//ʵ��һ�� sort �������������顢�����С�Լ�һ���ȽϺ�����Ϊ������
//���������ȽϺ�����ascending���������򣩺� descending���������򣩡�
//ʹ�� sort �����ֱ�����ͽ��������������򣬲���������
int cmp(const void* a, const void*b)
{
	return *(int*)a - *(int*)b;
}
void swap(char* a, char* b, int size)
{
	int i = 0;
	for (i = 0;i < size;i++)
	{
		char tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}

void sort_descending(void* arr, size_t sz, size_t size, int(*cmp)(const void* a, const void* b))
{
	int i = 0;
	for (i = 0;i < sz - 1;i++)
	{
		int j = 0;
		for (j = 0;j < sz - 1 - i;j++)
		{
			if (cmp((char*)arr + j * size, (char*)arr + (j + 1) * size) < 0)
			{
				swap((char*)arr + j * size, (char*)arr + (j + 1) * size,size);
			}
		}

	}
}

void sort_ascending(void* arr, size_t sz, size_t size, int(*cmp)(const void* a, const void* b))
{
	int i = 0;
	for (i = 0;i < sz - 1;i++)
	{
		int j = 0;
		for (j = 0;j < sz - 1 - i;j++)
		{
			if (cmp( (char*)arr+j*size,(char *)arr+(j+1)*size ) > 0)
			{
				swap((char*)arr + j * size, (char*)arr + (j + 1) *size,size);
			}
		}

	}
}
int main()
{
	int arr[]= { 5, 2, 8, 1, 3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	sort_ascending(arr, sz, sizeof(arr[0]), cmp);
	
	printf("����\n");
	int i = 0;
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	sort_descending(arr, sz, sizeof(arr[0]), cmp);
	printf("����\n");
	for (i = 0;i < sz;i++)
	{
		printf("%d ", arr[i]);
	}

}