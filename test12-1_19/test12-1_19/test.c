#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


#include <stdlib.h>
#include <string.h>

char* GetMemory(void)
{
    char* p = (char*)malloc(100);  // ��̬�����ڴ�
    if (p != NULL) {
        strcpy(p, "hello world");  // ���ַ�����������̬������ڴ�
    }
    return p;
}

void Test(void)
{
    char* str = NULL;
    str = GetMemory();  // ��ȡ�ڴ�
    if (str != NULL) {
        printf("%s\n", str);  // ʹ�ø�ʽ���ַ���
        free(str);  // ʹ����Ϻ��ͷ��ڴ�
    }
    else {
        printf("Memory allocation failed.\n");
    }
}

int main() {
    Test();
    return 0;
}
