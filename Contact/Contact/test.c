#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"
void menu()
{
	printf("************************************\n");
	printf("******  1. add    2. del      ******\n");
	printf("******  3. search 4. modify   ******\n");
	printf("******  5. show   6. sort     ******\n");
	printf("******  0. exit               ******\n");
	printf("************************************\n");
}

int main()
{
	Contact Con;
	InitContact(&Con);
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&Con);
			break;
		case 2:
			DelContact(&Con);
			break;
		case 3:
			SearchContact(&Con);
			break;
		case 4:
			ModifyContact(&Con);
			break;
		case 5:
			ShowContact(&Con);
			break;
		case 6:
			SortContact(&Con);
			break;
		case 0:
			printf("退出程序");
			break;
		default:
			printf("输入错误请重新输入");
			break;
		}
	} while (input);
	return 0;
}
