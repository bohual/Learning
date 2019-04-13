
#include <conio.h>	
#include <stdlib.h>
#include <string.h>

//����һ��ѧ��
typedef struct _Student
{
	char name[20]; //����
	int age;		//����	
	int stuNum;		//ѧ��
	int score;		//�ɼ�
}Student;

//�ڵ�
typedef	struct _Node
{
	Student stu;	//ѧ��
	struct _Node* pNext;	//ָ����һ���ڵ��ָ��

}Node;


//����һ��ͷ�ڵ�
Node *g_pHead = NULL;

//��ӭ
void Welcome(void);

//¼��ѧ����Ϣ
void InputStudent();

//��ӡѧ����Ϣ
void PrintStudent();

//����ѧ����Ϣ
void SaveStudent();

//��ȡѧ����Ϣ
void ReadStudent();

//ͳ��ѧ������
int CountStudent();

//����ѧ����Ϣ
Node* FindStudent();
//�޸�ѧ����Ϣ
void ModifyStudent();

//ɾ��ѧ����Ϣ
void DeleteStudent();