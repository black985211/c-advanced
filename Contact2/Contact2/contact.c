#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


void InitContact(Contact* pc)
{
	assert(pc);
	//初始化PeoInfo* data;
	PeoInfo* p = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (p == NULL)
	{
		perror("InitContact::calloc");
		return ;
	}
	pc->data = p;
	//初始化int sz;
	pc->sz = 0;
	//初始化int capacity;
	pc->capacity = DEFAULT_SZ;

	//加载文件信息到通讯录
	LoadContact(pc);
}
void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//给PeoInfo* data扩容
		PeoInfo* p = (PeoInfo*)realloc(pc->data, INC_SZ * sizeof(PeoInfo));
		if (p == NULL)
		{
			return ;
		}

		pc->data = p;
		pc->capacity += INC_SZ;
		printf("扩容成功，增加 %d 个位置\n", INC_SZ);
	}

}
void AddContact(Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);
	printf("姓名：\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("年龄：\n");
	scanf("%d", &pc->data[pc->sz].age); // 使用%d来扫描整数
	printf("性别：\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("地址：\n");
	scanf("%s", pc->data[pc->sz].addr);
	printf("电话：\n");
	scanf("%s", pc->data[pc->sz].tele);
	pc->sz++;
}

int FindName(Contact* pc,char name[NAME_MAX])
{
	assert(pc);
	int i = 0;
	for (i = 0;i < pc->sz;i++)
	{
		if (strcmp(pc->data[i].name, name) ==0)
		{
			return i;
		}
	}
	return -1;

}

void DelContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("通讯录为空");
		return;
	}
	char name[NAME_MAX] = "";
	printf("请输入要删除人的姓名：");
	scanf("%s", name);
	int ret = FindName(pc,name);
	if (ret == -1)
	{
		printf("没找到要删除的人\n");
		return;
	}
	
	int i = 0;
	for (i = ret;i < pc->sz - 1;i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

void SearchContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = "";
	printf("请输入要查找人的姓名：\n");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("未找到\n");
		return;
	}
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "名字", "年龄", "性别", "地址", "电话");
	printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[ret].name,
		pc->data[ret].age,
		pc->data[ret].sex,
		pc->data[ret].addr,
		pc->data[ret].tele);
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (-1 == pos)
	{
		printf("要修改的人不存在\n");
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

void PrintContact(Contact* pc)
{
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "名字", "年龄", "性别", "地址", "电话");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr,
			pc->data[i].tele);
	}
}
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	PrintContact(pc);
}

void NameCmp(const void * p1,const void * p2)
{
	return strcmp(((PeoInfo*)p1)->name , ((PeoInfo*)p2)->name);
}
void AgeCmp(const void* p1, const void* p2)
{
	return ((PeoInfo*)p1)->age-((PeoInfo*)p2)->age;
}
void SortContact(Contact* pc)
{
	assert(pc);
	if (pc->sz < 2)
	{
		printf("不需要排序");
		return;
	}

	printf("1.按名字排序\n");
	printf("2.按年龄排序\n");
	int input = 0;
	scanf("%d", &input);
	switch (input)
	{
		case 1:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), NameCmp);
		
			PrintContact(pc);
			break;
		case 2:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), AgeCmp);
		
			PrintContact(pc);
			break;

		default:
			printf("选择错误\n");
			break;
	}


}

void SavaContact(Contact* pc)
{
	FILE * pf =fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("SavaContact");
	}
	else
	{
		int i = 0;
		for (i = 0;i < pc->sz;i++)
		{
			fwrite(pc->data+i,sizeof(PeoInfo),1,pf);
		}
		fclose(pf);
		pf = NULL;
		printf("保存成功");
	}
	
}

void LoadContact(Contact* pc)
{
	FILE * pf=fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror(LoadContact);

	}
	else
	{
		PeoInfo tmp = { 0 };
		int i = 0;
		while (fread(&tmp, sizeof(PeoInfo), 1, pf))
		{
			CheckCapacity(pc);
			pc->data[i] = tmp;
			pc->sz++;
			i++;
		}
		fclose(pf);
		pf = NULL;
	}

}

void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
	pc = NULL;
}



