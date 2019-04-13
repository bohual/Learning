#include <stdio.h>
#include "StudentManageSystem.h"

int main()
{
	while (1)
	{
		Welcome();

		//从键盘里接受一个字符
		char ch = getch();
		
		switch (ch)
		{
			case '1':	//录入学生信息
				InputStudent();
				break;
			case '2':	//打印学生信息
				PrintStudent();
				break;
			case '3':	//保存学生信息
				SaveStudent();
				break;
			case '4':	//读取学生信息
				ReadStudent();
				break;
			case '5':	//统计所有学生人数
				printf("单身狗数量为:%d\n",CountStudent());
				system("pause");
				system("cls");
				break;
			case '6':	//查找学生信息
			{
				Node* p = FindStudent();
				if (p != NULL)
				{
					printf("编号：%d\t姓名：%s\t年龄：%d\t成绩：%d\n",
						p->stu.stuNum,
						p->stu.name,
						p->stu.age,
						p->stu.score);
				}
				else
					printf("没有找到单身狗的编号,已被人道毁灭.\n");
				system("pause");
				system("cls");
				break;
			}
			case '7':	//修改学生信息
				ModifyStudent();
				break; 
			case '8':	//删除学生信息
				DeleteStudent();
				system("pause");
				system("cls");
				break;
			case '0':	//退出系统
				printf("感谢使用单身狗管理系统.\n");
				return 0;
			default:
				printf("请重新输入：\n");
				system("pause");
				system("cls");
				break;
				
		}
	}


	return 0;
}

//欢迎
void Welcome(void)
{
	printf("*****************************************************************\n");
	printf("*\t\t欢迎使用湖工大单身狗管理系统v1.0\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t\t\t请选择功能列表\t\t\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t\t\t1.录入单身狗信息\t\t\t*\n");
	printf("*\t\t\t2.打印单身狗信息\t\t\t*\n");
	printf("*\t\t\t3.保存单身狗信息\t\t\t*\n");
	printf("*\t\t\t4.读取单身狗信息\t\t\t*\n");
	printf("*\t\t\t5.统计所有单身狗数量\t\t\t*\n");
	printf("*\t\t\t6.查找单身狗信息\t\t\t*\n");
	printf("*\t\t\t7.修改单身狗信息\t\t\t*\n");
	printf("*\t\t\t8.删除单身狗信息\t\t\t*\n");
	printf("*\t\t\t0.退出系统\t\t\t\t*\n");
	printf("*****************************************************************\n");


}

//录入学生信息
void InputStudent()
{
	//创建一个新节点
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;

	//头插法，尾插法
	//头插法
	if (g_pHead == NULL)
	{
		g_pHead = pNewNode;
	}
	else
	{
		pNewNode->pNext = g_pHead;
		g_pHead = pNewNode;
	}


	printf("请输入单身狗姓名：\n");
	scanf("%s", pNewNode->stu.name);//数组名本来就是一个地址，不用加&
	printf("请输入单身狗的年龄：\n");
	scanf("%d",& pNewNode->stu.age);
	printf("请输入单身狗的学号：\n");
	scanf("%d", &pNewNode->stu.stuNum);
	printf("请输入单身狗的成绩：\n");
	scanf("%d", &pNewNode->stu.score);
	printf("单身狗信息录入成功.\n");
	system("pause");
	system("cls");

}

void PrintStudent()
{
	system("pause");
	system("cls");
	printf("*****************************************************************\n");
	printf("*\t\t欢迎使用湖工大单身狗管理系统v1.0\t\t*\n");
	printf("*****************************************************************\n");
	printf("*\t学号\t*\t姓名\t*\t年龄\t*\t成绩\t*\n");
	printf("*****************************************************************\n");

	//遍历链表
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

//保存学生信息

void SaveStudent()
{
	//打开文件
	FILE* fp = fopen("D:\\student\\stuinfo.dat", "w");

	if (fp == NULL)
	{
		printf("打开文件失败.\n");
		return;
	}
	//遍历链表
	Node *p = g_pHead;
	while (p != NULL)
	{
		fwrite(&p->stu, 1, sizeof(Student), fp);
		p = p->pNext;
	}

	fclose(fp);
	printf("\n保存数据成功.\n");
	system("pause");
	system("cls");
}

void ReadStudent()
{
	//打开文件
	FILE* fp = fopen("D:\\student\\stuinfo.dat", "r");
	if (fp == NULL)
	{
		printf("打开文件失败\n");
		return;
	}
	//读取文件
	Student stu;
	while(fread(&stu, 1, sizeof(Student), fp))
	{
		//创建一个新节点
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
	printf("加载数据成功.\n");
	system("pause");
	system("cls");
}

//统计学生人数
int CountStudent()
{
	int nCount = 0;//学生总数
	Node *p = g_pHead;
	while (p != NULL)
	{
		nCount++;
		p = p->pNext;
	}
	printf("统计成功.\n");
	return nCount;

}
//查找学生
Node* FindStudent()
{

	int nStuNum;
	char szName[20];
	printf("请输入要查找的单身狗的编号：\n");
	scanf("%d", &nStuNum);

	printf("请输入要查找的单身狗的姓名：\n");
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

//修改学生信息
void ModifyStudent()
{
	int nStuNum;
	printf("请输入需要修改的单身狗的编号：\n");
	scanf("%d", &nStuNum);

	Node *p = g_pHead;
	while (p != NULL)
	{
		if (p->stu.stuNum == nStuNum)
		{
			printf("请输入要修改的单身狗的姓名 年龄 成绩：\n");

			scanf("%s %d %d", &p->stu.name, &p->stu.age, &p->stu.score);
			printf("修改成功.\n");
			break;

		}
		p = p->pNext;
	}
	if (p == NULL)
	{
		printf("没有该单身狗的信息");
		return;
	}
	system("pause");
	system("cls");
}

//删除学生信息
void DeleteStudent()
{
	int nStuNum;
	printf("请输入要删除的单身狗编号: \n");

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
			printf("删除单身狗成功.\n");
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
		printf("没有找到该单身狗.\n");
	}
	system("pause");
	system("cls");

}