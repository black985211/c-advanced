#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//1. malloc��free�Ļ���ʹ��
//��дһ������ʹ��mallocΪһ��������������ڴ棬Ȼ��ʹ��free�ͷŸ��ڴ档��ȷ�����ͷ��ڴ�֮ǰ������������Ѿ�����ӡ������

//int main()
//{
//	int* arr = (int*)malloc(10 * sizeof(int));
//	if (arr == NULL)
//	{
//		perror("arr:NULL");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0;i < 10;i++)
//	{
//		arr[i] = i+1;
//	}
//	for (i = 0;i < 10;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}

//2. ��̬����ʵ��
//����һ�����򣬶�̬����һ������������ڴ档����Ҫ���û���������Ĵ�С��Ȼ��������Ӧ����������������ӡ����Щ�������ͷ��ڴ档

//int main()
//{
//	int sz = 0;
//	printf("����������Ĵ�С��");
//	scanf("%d", &sz);
//	int* arr = (int*)malloc(sz * sizeof(int));
//	if (arr == NULL)
//	{
//		perror("arr:NULL");
//		return 1;
//
//	}
//	int i = 0;
//	for (i = 0;i < sz;i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (i = 0;i < sz;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}

//3. �ڴ�й©���
//��дһ�������������ڴ��һ���ַ������飬���ں�������ʱû���ͷŸ��ڴ档���ŷ������򣬿����Ƿ�ᷢ���ڴ�й©��������޸���


//void memory_leak_demo() {
//    // ��̬�����ڴ��һ���ַ�����
//    char* arr = (char*)malloc(10 * sizeof(char));
//    if (arr == NULL) {
//        perror("Memory allocation failed");
//        return;
//    }
//
//    // ģ���arr��ʹ�ã�����洢һЩ�ַ�
//    arr[0] = 'A';
//    arr[1] = 'B';
//    // ... ���Լ���ʹ���������
//
//    // ��ʾû���ͷ��ڴ��������������ʱ arr û�б� free
//    // û�е��� free(arr)������ͷ������ڴ�й©
//    // �������ʱ�᷵�� arr ָ����ڴ������޷�������
//}
//
//int main() {
//    memory_leak_demo(); // ��ʾ�ڴ�й©
//
//    // Ϊ���޸��ڴ�й©������Ӧ���ֶ��ͷ��ڴ�
//    // ����ڴ�й©���ں�������ǰ���� free �ͷ��ڴ�
//    // memory_leak_demo(); -> ����ں���ĩβ�ͷ��ڴ棬�Ͳ������ڴ�й©
//
//    return 0;
//}


//4. ָ���ָ��
//��������һ��ָ��ָ��һ����̬����Ķ�ά���飬�����ȷ���ʺ��ͷ��ڴ棿
//int** matrix;
//���д����ʵ�����¹��ܣ�
//Ϊmatrix��̬�����ڴ棬���ڴ洢һ��n x m�Ķ�ά���顣
//������鲢��ӡ��
//�ͷŷ�����ڴ档

//int main()
//{
//	int n = 3;
//	int m = 3;
//	int** matrix = (int**)malloc(n * sizeof(int*));
//	if (matrix == NULL) {
//		printf("�ڴ����ʧ�ܣ�\n");
//		return 1; // �������ʧ�ܣ��˳�����
//	}
//	int i = 0;
//	for(i = 0;i < n;i++)
//	{
//		matrix[i] = (int*)malloc(m * sizeof(int));
//	}
//	for (i = 0; i < n; i++) {
//		free(matrix[i]); // �ͷ�ÿһ�е��ڴ�
//		matrix[i] = NULL; // ����ָ����ΪNULL
//	}
//	free(matrix); // �ͷ���ָ��������ڴ�
//	matrix = NULL; // ��matrixָ����ΪNULL
//
//	return 0;
//}

//5. �ڴ���չ
//��дһ��������Ϊһ��������������ڴ棬Ȼ��Ҫ���û��������ݡ�
//���ţ�����û����������������ԭ��������ڴ��С��ʹ��realloc��չ�ڴ棬�������������ݡ�����ӡ��������ݡ�

//int main()
//{
//    int capacity = 3;
//    int* arr = (int*)malloc(capacity * sizeof(int)); // ��ʼ���ڴ�
//    if (arr == NULL)
//    {
//        printf("Memory allocation failed\n");
//        return 1;
//    }
//
//    int input = 0;
//    int i = 0;
//
//    while (1)
//    {
//        // ��������
//        printf("������һ��������");
//        scanf("%d", &input);
//
//        // �洢�����ֵ
//        arr[i] = input;
//        i++;
//
//        // �ж��Ƿ���Ҫ����
//        if (i >= capacity)
//        {
//            // ���ݣ�����������
//            int* ptr = (int*)realloc(arr, 2 * capacity * sizeof(int));
//            if (ptr == NULL)
//            {
//                printf("Memory reallocation failed\n");
//                free(arr);
//                return 1;
//            }
//            arr = ptr;
//            capacity *= 2;  // ��������Ϊ�������ֵ
//            printf("���ݳɹ����µ�����Ϊ %d ��������\n", capacity);
//
//            
//           
//        }
//
//        // �������ﵽ������������� 10�����˳�ѭ��
//        if (i == 10)
//        {
//            break;
//        }
//    }
//
//    // ��ӡ��������
//    printf("������������ݣ�");
//    for (int j = 0; j < i; j++)
//    {
//        printf("%d ", arr[j]);
//    }
//    printf("\n");
//
//    // �ͷ��ڴ�
//    free(arr);
//    arr = NULL;
//
//    return 0;
//}

//6. ʹ��calloc
//дһ������ʹ��callocΪһ����������ڴ档
//��ʹ��malloc�Ĳ�֮ͬ�����ڣ�calloc�Ὣ�����ڴ��ʼ��Ϊ�㡣���ӡ�������ݣ����ͷ��ڴ档
int main()
{
    int* p = (int*)calloc(3,sizeof(int));
    if (p == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
        return 1;
    }
    int i = 0;
    for(i = 0;i < 3;i++)
    {
        printf("%d ", p[i]);
    }
    free(p);
    p = NULL;
    return 0;
}

