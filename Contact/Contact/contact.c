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
		printf("ͨѶ¼�����޷����");
		return;
	}
	printf("����������:");
	scanf("%s", p->data[p->sz].name);
	printf("����������:");
	scanf("%d", &(p->data[p->sz].age));
	printf("�������Ա�:");
	scanf("%s", p->data[p->sz].sex);
	printf("������סַ:");
	scanf("%s", p->data[p->sz].addr);
	printf("������绰:");
	scanf("%s", p->data[p->sz].tele);
	p->sz++;
}
void DelContact(Contact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("ͨѶ¼��\n");
		return;
	}
	char name[20] = {0};
	printf("������Ҫɾ�������֣�");
	scanf("%s", name);
	int ret =FindContactName(p, name);
	if (ret == -1)
	{
		printf("û���ҵ�����");
	}
	
	for (int i = ret;i < p->sz - 1;i++)
	{
		p->data[i] = p->data[i + 1];
	}
	p->sz--;
	printf("ɾ���ɹ�\n");

}
void SearchContact(const Contact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("ͨѶ¼��\n");
		return;
	}
	char name[20] = "";
	printf("������Ҫ�����˵����֣�");
	scanf("%s", name);
	int ret = FindContactName(p, name);
	if (ret == -1)
	{
		printf("���޴���\n");
		return;
	}
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
	printf("%-20s\t%-4d\t%-5s\t%-20s\t%-12s\n",p->data[ret].name,p->data[ret].age, p->data[ret].sex, p->data[ret].addr, p->data[ret].tele);
}
void ModifyContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("ͨѶ¼��\n");
		return;
	}
	char name[20] = "";
	printf("������Ҫ�޸���Ϣ�˵����֣�");
	scanf("%s", name);
	int pos = FindContactName(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
		return;
	}
	printf("����������:>");
	scanf("%s", pc->data[pos].name);
	printf("����������:>");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�:>");
	scanf("%s", pc->data[pos].sex);
	printf("�������ַ:>");
	scanf("%s", pc->data[pos].addr);
	printf("������绰:>");
	scanf("%s", pc->data[pos].tele);

	printf("�޸����\n");

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
		printf("��ϵ���������㣬�޷��������Ҫ����!\n");
		return;
	}
	printf("��ѡ������ʽ:\n");
	printf("1. ����������\n");
	printf("2. ����������\n");
	printf("������ѡ��:>");
	int choice = 0;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		qsort(p->data, p->sz, sizeof(PeoInfo), NameCmp);
		printf("����ɹ�\n");
		break;
	case 2:
		qsort(p->data, p->sz, sizeof(PeoInfo), AgeCmp);
		printf("����ɹ�\n");
		break;
	default:
		printf("�������\n");
		break;

	}
	
}


void ShowContact(const Contact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("ͨѶ¼��\n");
		return;
	}
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
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