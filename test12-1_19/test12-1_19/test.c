#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


#include <stdlib.h>
#include <string.h>

char* GetMemory(void)
{
    char* p = (char*)malloc(100);  // 动态分配内存
    if (p != NULL) {
        strcpy(p, "hello world");  // 将字符串拷贝到动态分配的内存
    }
    return p;
}

void Test(void)
{
    char* str = NULL;
    str = GetMemory();  // 获取内存
    if (str != NULL) {
        printf("%s\n", str);  // 使用格式化字符串
        free(str);  // 使用完毕后释放内存
    }
    else {
        printf("Memory allocation failed.\n");
    }
}

int main() {
    Test();
    return 0;
}
