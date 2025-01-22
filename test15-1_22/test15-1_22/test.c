#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	char* p[] = { "shanghai","beijing","hongkong" };
//	printf("%c\n", p[1][3]);
//	printf("%c", *(p[1]+3));
//
//	return 0;
//
//}

//int main()
//{
//	int a = 0;
//	scanf("%d", &a);//123 456 789
//	char arr[100] = { 0 };
//	int i = 0;
//	int m = 0;
//	while (a)
//	{
//		if (m != 0 && m % 3 == 0)
//		{
//			arr[i] = ',';
//			i++;
//		}
//		arr[i] = a % 10+'0';
//		i++;
//		a /= 10;
//		m++;
//	}//i=11
//	int j = 0;
//	for (j = i - 1;j >= 0;j--)
//	{
//		printf("%c", arr[j]);
//	}
//
//	return 0;
//}
#include<string.h>

//int main() {
//    char arr1[100] = "";
//    char arr2[100] = "";
//
//    printf("Enter the first string: ");
//    scanf("%[^\n]%*c", arr1); // 读取一行字符串，包括空格
//    printf("Enter the characters to remove: ");
//    scanf("%s", arr2);        // 读取一个单词
//
//    int len1 = strlen(arr1);
//    int len2 = strlen(arr2);
//
//    for (int i = 0; i < len2; i++) {
//        for (int j = 0; j < len1; j++) {
//            if (arr1[j] == arr2[i]) {
//                // 左移剩余的字符
//                for (int k = j; k < len1 - 1; k++) {
//                    arr1[k] = arr1[k + 1];
//                }
//                arr1[len1 - 1] = '\0'; // 补充字符串终止符
//                len1--;                // 动态更新字符串长度
//                j--;                   // 确保当前位置重新检查
//            }
//        }
//    }
//
//    // 输出结果
//    printf("Result: %s\n", arr1);
//
//    return 0;
//}
int if_not_exist(char ch, char* str)
{
    while (*str)
    {
        if (ch != *str)
        {
            return 0;
        }
        str++;
    }
    return 1;
}
int main() {
    char arr1[100] = "";
    char arr2[100] = "";

    printf("Enter the first string: ");
    scanf("%[^\n]%*c", arr1); // 读取一行字符串，包括空格
    printf("Enter the characters to remove: ");
    scanf("%s", arr2);        // 读取一个单词

    int len1 = strlen(arr1);
    int i = 0;
    for (i = 0;i < len1;i++)
    {
        if (if_not_exist(arr1[i], arr2))
        {
            printf("%c", arr1[i]);
        }
    }
    return 0;
}
