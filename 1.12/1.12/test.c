#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <assert.h>
#include <string.h>

//char* my_strcpy(char* arr1, const char* arr2)
//{
//    char* ret = arr1;
//    while (*arr1++ = *arr2++)
//    {
//        ;
//    }
//    return ret;
//}
//int main()
//{
//    char arr1[30] = "";
//    char arr2[] = "hello world";
//    printf("%s", my_strcpy(arr1, arr2));
//}

// ���ַ���ֵ��һ����
//char* my_strcat(char* dest, const char* src)
//{
//    assert(dest && src);
//    char* ret = dest;
//
//    // ��Ŀ��ռ��\0
//    while (*dest)
//    {
//        dest++;
//    }
//
//    // ׷��
//    while ((*dest++ = *src++));
//
//    return ret;
//}
//
//int main()
//{
//    char arr[20] = "hello ";
//    const char* p = "world"; // ʹ�� const char* ����ȫ
//
//    // ���շ���ֵ����ѡ��
//    char* result = my_strcat(arr, p);
//
//    // ʹ�÷���ֵ
//    printf("%s\n", result);
//
//    // ����ֱ���� printf ��ʹ��
//    // printf("%s\n", my_strcat(arr, p));
//
//    return 0;
//}

//int my_strcmp(const char* arr1, const char* arr2)
//{
//	assert(arr1 && arr2); // ȷ��ָ�벻Ϊ��
//	while (*arr1 == *arr2)
//	{
//		if (*arr1=='\0')
//		{
//			return 0;
//		}
//		arr1++;
//		arr2++;
//	}
//	return *arr1 - *arr2;
//}
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = "abceid";
//	int ret = my_strcmp(arr1, arr2);
//	if (ret > 0)
//	{
//		printf("arr1>arr2");
//	}
//	else if (ret == 0)
//	{
//		printf("arr1=arr2");
//	}
//	else
//	{
//		printf("arr1<arr2");
//	}
//
//}

//int main()
//{
//	char arr1[100] = "*********";
//	char arr2[] = "yanggang";
//	strncpy(arr1, arr2, 3);
//	printf("%s", arr1);
//}

//int main()
//{
//	char arr1[100] = "*********";
//	char arr2[] = "yanggang";
//	strncat(arr1, arr2, 3);
//	printf("%s", arr1);
//
//}

//int main()
//{
//	char arr1[100] = "yanh*****";
//	char arr2[] = "yanggang";
//	int ret = strncmp(arr1, arr2, 4);
//	printf("%d ", ret);
//}

//int main()
//{
//	char arr1[100] = "yanh*****";
//	char arr2[] = "a";
//	char* p = strstr(arr1, arr2);
//	if (p == NULL)
//	{
//		printf("�Ҳ���");
//	}
//	else
//		printf("%s", p);
//}


//char* my_strstr(const char* arr1, const char* arr2)
//{
//
//}
//int main()
//{
//	char arr1[100] = "yanh*****";
//	char arr2[] = "a";
//	char* p =my_strstr(arr1, arr2);
//	if (p == NULL)
//	{
//		printf("�Ҳ���");
//	}
//	else
//		printf("%s", p);
//}


int main()
{
	char arr[] = "hello,world!welcome to rugao.";
	const char* p = " ,.!";
	char* buff = strtok(arr,p);
	while (buff != NULL)
	{
		printf("%s\n", buff);
		buff = strtok(NULL, p);
	}
	return 0;
}

