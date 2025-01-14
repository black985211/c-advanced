#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

int FindContactName(Contact * p, char *name)
{
	assert(p && name);
	int i = 0;
	for (i = 0;i < p->sz;i++)
	{
		if (strcmp(name, p->data[i].name) == 0)
		{
			
			return i;
		}
	}
	return -1;
}
void InitContact(Contact * p)
{
	p->sz = 0;
	memset(p->data, 0, sizeof(p->data));

}
void AddContact(Contact* p)
{
	assert(p);
	if (p->sz == MAX)
	{
		printf("通讯录已满无法添加");
		return;
	}
	printf("请输入名字:");
	scanf("%s", p->data[p->sz].name);
	printf("请输入年龄:");
	scanf("%d", &(p->data[p->sz].age));
	printf("请输入性别:");
	scanf("%s", p->data[p->sz].sex);
	printf("请输入住址:");
	scanf("%s", p->data[p->sz].addr);
	printf("请输入电话:");
	scanf("%s", p->data[p->sz].tele);
	p->sz++;
}
void DelContact(Contact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("通讯录空\n");
		return;
	}
	char name[20] = {0};
	printf("请输入要删除的名字：");
	scanf("%s", name);
	int ret =FindContactName(p, name);
	if (ret == -1)
	{
		printf("没有找到此人");
	}
	
	for (int i = ret;i < p->sz - 1;i++)
	{
		p->data[i] = p->data[i + 1];
	}
	p->sz--;
	printf("删除成功\n");

}
void SearchContact(const Contact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("通讯录空\n");
		return;
	}
	char name[20] = "";
	printf("请输入要查找人的名字：");
	scanf("%s", name);
	int ret = FindContactName(p, name);
	if (ret == -1)
	{
		printf("查无此人\n");
		return;
	}
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "名字", "年龄", "性别", "地址", "电话");
	printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n",p->data[ret].name,p->data[ret].age, p->data[ret].sex, p->data[ret].addr, p->data[ret].tele);
}
void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录空\n");
		return;
	}
	char name[20] = "";
	printf("请输入要修改信息人的名字：");
	scanf("%s", name);
	int pos = FindContactName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别:>");
	scanf("%s", pc->data[pos].sex);
	printf("请输入地址:>");
	scanf("%s", pc->data[pos].addr);
	printf("请输入电话:>");
	scanf("%s", pc->data[pos].tele);

	printf("修改完成\n");

}
int NameCmp(const void* p1, const void* p2)
{
	PeoInfo* pa = (PeoInfo*)p1;
	PeoInfo* pb = (PeoInfo*)p2;
	return strcmp(pa->name, pb->name);

}
int AgeCmp(const void* p1, const void* p2)
{
	PeoInfo* pa = (PeoInfo*)p1;
	PeoInfo* pb = (PeoInfo*)p2;
	return pa->age-pb->age;
}
void SortContact(Contact* p)
{
	assert(p);
	if (p->sz <= 1)
	{
		printf("联系人数量不足，无法排序或不需要排序!\n");
		return;
	}
	printf("请选择排序方式:\n");
	printf("1. 按姓名排序\n");
	printf("2. 按年龄排序\n");
	printf("请输入选择:>");
	int choice = 0;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		qsort(p->data, p->sz, sizeof(PeoInfo), NameCmp);
		printf("排序成功\n");
		break;
	case 2:
		qsort(p->data, p->sz, sizeof(PeoInfo), AgeCmp);
		printf("排序成功\n");
		break;
	default:
		printf("输入错误\n");
		break;

	}
	
}


void ShowContact(const Contact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("通讯录空\n");
		return;
	}
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "名字", "年龄", "性别", "地址", "电话");
	int i = 0;
	for (i = 0;i < p->sz;i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", p->data[i].name, 
			p->data[i].age,
			p->data[i].sex,
			p->data[i].addr,
			p->data[i].tele
		);
	}
}