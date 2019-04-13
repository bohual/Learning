#include <stdio.h>
#include "StudentManageSystem.h"

int main()
{
	while (1)
	{
		Welcome();

		//�Ӽ��������һ���ַ�
		char ch = getch();
		
		switch (ch)
		{
			case '1':	//¼��ѧ����Ϣ
				InputStudent();
				break;
			case '2':	//��ӡѧ����Ϣ
				PrintStudent();
				break;
			case '3':	//����ѧ����Ϣ
				SaveStudent();
				break;
			case '4':	//��ȡѧ����Ϣ
				ReadStudent();
				break;
			case '5':	//ͳ������ѧ������
				printf("��������Ϊ:%d\n",CountStudent());
				system("pause");
				system("cls");
				break;
			case '6':	//����ѧ����Ϣ
			{
				Node* p = FindStudent();
				if (p != NULL)
				{
					printf("��ţ�%d\t������%s\t���䣺%d\t�ɼ���%d\n",
						p->stu.stuNum,
						p->stu.name,
						p->stu.age,
						p->stu.score);
				}
				else
					printf("û���ҵ������ı��,�ѱ��˵�����.\n");
				system("pause");
				system("cls");
				break;
			}
			case '7':	//�޸�ѧ����Ϣ
				ModifyStudent();
				break; 
			case '8':	//ɾ��ѧ����Ϣ
				DeleteStudent();
				system("pause");
				system("cls");
				break;
			case '0':	//�˳�ϵͳ
				printf("��лʹ�õ�������ϵͳ.\n");
				return 0;
			default:
				printf("���������룺\n");
				system("pause");
				system("cls");
				break;
				
		}
	}


	return 0;
}

//��ӭ
void Welcome(void)
{
	printf("*****************************************************************\n");
	printf("*\t\t��ӭʹ�ú�����������ϵͳv1.0\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t\t\t��ѡ�����б�\t\t\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t\t\t1.¼�뵥����Ϣ\t\t\t*\n");
	printf("*\t\t\t2.��ӡ������Ϣ\t\t\t*\n");
	printf("*\t\t\t3.���浥����Ϣ\t\t\t*\n");
	printf("*\t\t\t4.��ȡ������Ϣ\t\t\t*\n");
	printf("*\t\t\t5.ͳ�����е�������\t\t\t*\n");
	printf("*\t\t\t6.���ҵ�����Ϣ\t\t\t*\n");
	printf("*\t\t\t7.�޸ĵ�����Ϣ\t\t\t*\n");
	printf("*\t\t\t8.ɾ��������Ϣ\t\t\t*\n");
	printf("*\t\t\t0.�˳�ϵͳ\t\t\t\t*\n");
	printf("*****************************************************************\n");


}

//¼��ѧ����Ϣ
void InputStudent()
{
	//����һ���½ڵ�
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;

	//ͷ�巨��β�巨
	//ͷ�巨
	if (g_pHead == NULL)
	{
		g_pHead = pNewNode;
	}
	else
	{
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}


	printf("�����뵥��������\n");
	scanf("%s", pNewNode->stu.name);//��������������һ����ַ�����ü�&
	printf("�����뵥�������䣺\n");
	scanf("%d",& pNewNode->stu.age);
	printf("�����뵥����ѧ�ţ�\n");
	scanf("%d", &pNewNode->stu.stuNum);
	printf("�����뵥���ĳɼ���\n");
	scanf("%d", &pNewNode->stu.score);
	printf("������Ϣ¼��ɹ�.\n");
	system("pause");
	system("cls");

}

void PrintStudent()
{
	system("pause");
	system("cls");
	printf("*****************************************************************\n");
	printf("*\t\t��ӭʹ�ú�����������ϵͳv1.0\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\tѧ��\t*\t����\t*\t����\t*\t�ɼ�\t*\n");
	printf("*****************************************************************\n");

	//��������
	Node *p = g_pHead;
	while (p != NULL)
	{
		printf("*\t%d\t*\t%s\t*\t%d\t*\t%d\t*\n", 
			p->stu.stuNum,
			p->stu.name, 
			p->stu.age,
			p->stu.score);
		p = p->pNext;
	}
	system("pause");
	system("cls");
}

//����ѧ����Ϣ

void SaveStudent()
{
	//���ļ�
	FILE* fp = fopen("D:\\student\\stuinfo.dat", "w");

	if (fp == NULL)
	{
		printf("���ļ�ʧ��.\n");
		return;
	}
	//��������
	Node *p = g_pHead;
	while (p != NULL)
	{
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->pNext;
	}

	fclose(fp);
	printf("\n�������ݳɹ�.\n");
	system("pause");
	system("cls");
}

void ReadStudent()
{
	//���ļ�
	FILE* fp = fopen("D:\\student\\stuinfo.dat", "r");
	if (fp == NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	//��ȡ�ļ�
	Student stu;
	while(fread(&stu, 1, sizeof(Student), fp))
	{
		//����һ���½ڵ�
		Node* pNewNode = (Node *)malloc(sizeof(Node));

		pNewNode->pNext = NULL;
		memcpy(pNewNode, &stu, sizeof(Student));
		if (g_pHead == NULL)
		{
			g_pHead = pNewNode;

		}
		else
		{
			pNewNode->pNext = g_pHead;
			g_pHead = pNewNode;

		}
	}


	fclose(fp);
	printf("�������ݳɹ�.\n");
	system("pause");
	system("cls");
}

//ͳ��ѧ������
int CountStudent()
{
	int nCount = 0;//ѧ������
	Node *p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;
	}
	printf("ͳ�Ƴɹ�.\n");
	return nCount;

}
//����ѧ��
Node* FindStudent()
{

	int nStuNum;
	char szName[20];
	printf("������Ҫ���ҵĵ����ı�ţ�\n");
	scanf("%d", &nStuNum);

	printf("������Ҫ���ҵĵ�����������\n");
	scanf("%s", szName);
	Node *p = g_pHead;
	while (p != NULL)
	{
		if (p->stu.stuNum == nStuNum || strcmp(szName, p->stu.name))
		{
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}

//�޸�ѧ����Ϣ
void ModifyStudent()
{
	int nStuNum;
	printf("��������Ҫ�޸ĵĵ����ı�ţ�\n");
	scanf("%d", &nStuNum);

	Node *p = g_pHead;
	while (p != NULL)
	{
		if (p->stu.stuNum == nStuNum)
		{
			printf("������Ҫ�޸ĵĵ��������� ���� �ɼ���\n");

			scanf("%s %d %d", &p->stu.name, &p->stu.age, &p->stu.score);
			printf("�޸ĳɹ�.\n");
			break;

		}
		p = p->pNext;
	}
	if (p == NULL)
	{
		printf("û�иõ�������Ϣ");
		return;
	}
	system("pause");
	system("cls");
}

//ɾ��ѧ����Ϣ
void DeleteStudent()
{
	int nStuNum;
	printf("������Ҫɾ���ĵ������: \n");

	scanf("%d", &nStuNum);
	Node *p1, *p2;
	if (g_pHead->stu.stuNum == nStuNum)
	{
		p1 = g_pHead;
		g_pHead = g_pHead->pNext;
		free(g_pHead);
		return;
	}
	Node *p = g_pHead;

	while (p->pNext != NULL)
	{
		if (p->pNext->stu.stuNum == nStuNum)
		{
			p2 = p->pNext;
			p->pNext = p->pNext->pNext;
			free(p2);
			printf("ɾ�������ɹ�.\n");
			return;
		}
		p = p->pNext;
		if (p->pNext == NULL)
		{
			break;
		}
	}
	if (p->pNext = NULL)
	{
		printf("û���ҵ��õ���.\n");
	}
	system("pause");
	system("cls");

}