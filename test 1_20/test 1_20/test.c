#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void find_single_dog(int arr[], int sz, int single_dog[])
//{
//    int ret = 0;
//    int i = 0;
//    // ��һ��ѭ�����������е�����Ԫ�ؽ����������
//    for (i = 0; i < sz; i++)
//    {
//        ret ^= arr[i];// 0110 ^ 1000 = 1110 
//    }
//    // ����ret����һλ������λ��1
//    int pos = 0;
//    // �ڶ���ѭ�����ҳ�ret�����ұߵ�1��λ��
//    for (i = 0; i < 32; i++)
//    {
//        if (((ret >> i) & 1) == 1) //1110
//        {
//            pos = i;// i =1
//            break;
//        }
//    }
//    // ������ѭ��������posλ�Ĳ�ͬ��������ֳ����飬�ֱ�������
//    for (i = 0; i < sz; i++)  //1 2 3 4 5 1 2 3 4 6
//    {
//        if (((arr[i] >> pos) & 1) == 1)  
//        {
//            single_dog[0] ^= arr[i];  // �����λ��1�����뵽single_dog[0]
//            //2
//        }
//        else
//        {
//            single_dog[1] ^= arr[i];  // �����λ��0�����뵽single_dog[1]
//            //1 
//        }
//    }
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,8,1,2,3,4,6 };//11 33 5   22 44 6
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int single_dog[2] = {0};
//
//	find_single_dog(arr, sz, single_dog);
//	printf("%d %d\n", single_dog[0], single_dog[1]);
//	return 0;
//}

//1.ret = a ^ b
//2.�ڼ�λΪ1
//3.����
//void find_single_dog(int arr[],int sz,int single_dog[2])
//{
//	int ret = 0;
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		ret ^= arr[i];// 6^8=0110^1000=1110
//	}
//	int pos = 0;
//	for (i = 0;i < 32;i++)
//	{
//		if (((ret >> i) & 1) == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	for (i = 0;i<sz;i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			single_dog[0] ^= arr[i];
//		}
//		else
//		{
//			single_dog[1] ^= arr[i];
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,6,1,2,3,4,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int single_dog[2] = { 0 };
//	find_single_dog(arr, sz, single_dog);
//	printf("%d %d\n", single_dog[0], single_dog[1]);
//	return 0;
//}

#include<stdlib.h>
//int main()
//{
//	int ret = atoi("12345");
//	printf("%d ", ret);
//	return 0;
//}
#include<assert.h>
#include <ctype.h>

enum State
{
	VALID,
	INVALID
}state = INVALID;//Ĭ�ϱ�ʾ�Ƿ�

int my_atoi(const char* str)
{
	assert(str);
	if (*str == '\0')
	{
		return 0;
	}
	//�����հ��ַ�
	while (isspace(*str))
	{
		str++;
	}
	int flag = 1;
	if (*str == '+')
	{
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	long long ret = 0;
	while (*str)
	{
		if (isdigit(*str))
		{
			ret = ret * 10 + flag * (*str - '0');
			if (ret > INT_MAX)
			{
				return INT_MAX;
			}
			else if (ret < INT_MIN)
			{
				return INT_MIN;
			}
		}
		else
		{
			return (int)ret;
		}
		str++;
	}

	state = VALID;
	return (int)ret;
}

int main()
{
	int ret = my_atoi("123411111111111111115");

	if (state == VALID)
		printf("%d\n", ret);
	else
		printf("�Ƿ��ַ���ת��,%d\n", ret);

	return 0;
}
