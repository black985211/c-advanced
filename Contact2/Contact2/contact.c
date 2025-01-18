#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"


void InitContact(Contact* pc)
{
	assert(pc);
	//��ʼ��PeoInfo* data;
	PeoInfo* p = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (p == NULL)
	{
		perror("InitContact::calloc");
		return ;
	}
	pc->data = p;
	//��ʼ��int sz;
	pc->sz = 0;
	//��ʼ��int capacity;
	pc->capacity = DEFAULT_SZ;

	//�����ļ���Ϣ��ͨѶ¼
	LoadContact(pc);
}
void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//��PeoInfo* data����
		PeoInfo* p = (PeoInfo*)realloc(pc->data, INC_SZ * sizeof(PeoInfo));
		if (p == NULL)
		{
			return ;
		}

		pc->data = p;
		pc->capacity += INC_SZ;
		printf("���ݳɹ������� %d ��λ��\n", INC_SZ);
	}

}
void AddContact(Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);
	printf("������\n");
	scanf("%s", pc->data[pc->sz].name);
	printf("���䣺\n");
	scanf("%d", &pc->data[pc->sz].age); // ʹ��%d��ɨ������
	printf("�Ա�\n");
	scanf("%s", pc->data[pc->sz].sex);
	printf("��ַ��\n");
	scanf("%s", pc->data[pc->sz].addr);
	printf("�绰��\n");
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
		printf("ͨѶ¼Ϊ��");
		return;
	}
	char name[NAME_MAX] = "";
	printf("������Ҫɾ���˵�������");
	scanf("%s", name);
	int ret = FindName(pc,name);
	if (ret == -1)
	{
		printf("û�ҵ�Ҫɾ������\n");
		return;
	}
	
	int i = 0;
	for (i = ret;i < pc->sz - 1;i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = "";
	printf("������Ҫ�����˵�������\n");
	scanf("%s", name);
	int ret = FindName(pc, name);
	if (ret == -1)
	{
		printf("δ�ҵ�\n");
		return;
	}
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
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
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos = FindName(pc, name);
	if (-1 == pos)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
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

void PrintContact(Contact* pc)
{
	int i = 0;
	printf("%-20s\t%-4s\t%-5s\t%-20s\t%-12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
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
		printf("����Ҫ����");
		return;
	}

	printf("1.����������\n");
	printf("2.����������\n");
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
			printf("ѡ�����\n");
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
		printf("����ɹ�");
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



