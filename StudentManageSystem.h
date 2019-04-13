
#include <conio.h>	
#include <stdlib.h>
#include <string.h>

//定义一个学生
typedef struct _Student
{
	char name[20]; //姓名
	int age;		//年龄	
	int stuNum;		//学号
	int score;		//成绩
}Student;

//节点
typedef	struct _Node
{
	Student stu;	//学生
	struct _Node* pNext;	//指向下一个节点的指针

}Node;


//定义一个头节点
Node *g_pHead = NULL;

//欢迎
void Welcome(void);

//录入学生信息
void InputStudent();

//打印学生信息
void PrintStudent();

//保存学生信息
void SaveStudent();

//读取学生信息
void ReadStudent();

//统计学生人数
int CountStudent();

//查找学生信息
Node* FindStudent();
//修改学生信息
void ModifyStudent();

//删除学生信息
void DeleteStudent();
