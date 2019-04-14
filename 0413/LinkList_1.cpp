#include <stdio.h>	
#include <malloc.h>
#include <Windows.h>
#define FUNCTION printf("--------------------%s-------------------\n",__FUNCTION__);

typedef char LinkType;

typedef struct LinkNode
{
	LinkType data;
	struct LinkNode * next;
}LinkNode;

void LinkListInit(LinkNode** head);

void PrintChar(LinkNode* head, char *msg);

void DestroyNode(LinkNode * node);

void LinkListDestroy(LinkNode ** head);

LinkNode* CreateNewNode(LinkType value);

void LinkListPushBack(LinkNode** head, LinkType value);

void LinkListPopBack(LinkNode** head);

void LinkListPushHead(LinkNode ** head, LinkType value);

void LinkListPopHead(LinkNode ** head);

LinkNode* LinkListFind(LinkNode * head, LinkType value);

void LinkListInsertBack(LinkNode *pos, LinkType value);

void LinkListInsertBefo(LinkNode ** head, LinkNode *pos, LinkType value);

void LinkListDelVal(LinkNode ** head, LinkType value);

int IsLast(LinkNode * head, LinkNode* pos);

int LinkListSize(LinkNode * head);

void LinkListDelete(LinkNode ** head);

LinkNode * FindPrevious(LinkNode * head, LinkType value);

void PrintChar(LinkNode * head, const LinkType * data)
{
	if (head == NULL)
		return;
	printf("%s\n\n", data);
	while (head)
	{
		printf("[%c]", head->data);
		head = head->next;
	}
	printf("\n\n");
}

int IsEmpty(LinkNode * head)
{
	return head->next == NULL;
}

LinkNode * CreateNewNode(LinkType value)
{
	LinkNode * NewNode = (LinkNode *)malloc(sizeof(LinkNode));

	if (NewNode == NULL)
	{
		printf("malloc failed!.\n");
	}
	NewNode->data = value;
	NewNode->next = NULL;

	return NewNode;
}

void DestroyNode(LinkNode * Node)
{
	if (Node == NULL)
		return;
	free(Node);
}

void LinkListInit(LinkNode ** head)
{
	if (head == NULL)
		return;
	*head = NULL;
}

void LinkListPushHead(LinkNode ** head, LinkType value)
{
	if (head == NULL)
		return;
	LinkNode * NewNode = CreateNewNode(value);
	NewNode->next = *head;
	*head = NewNode;
	return;
}

void LinkListPushBack(LinkNode ** head, LinkType value)
{
	if (head == NULL)
		return;
	if (*head == NULL)
	{
		*head = CreateNewNode(value);
		return;
	}
	LinkNode * phead = *head;
	while (phead->next)
	{
		phead = phead->next;
	}
	phead->next = CreateNewNode(value);
	return;
		
}

void LinkListPopHead(LinkNode ** head)
{
	if (head == NULL)
		return;
	if (*head == NULL)
		return;
	LinkNode * cur = *head;
	*head = (*head)->next;
	DestroyNode(cur);
	return;
}

LinkNode * LinkListFind(LinkNode * head, LinkType value)
{
	if (head == NULL)
		return NULL;
	LinkNode *cur = head;
	for (; cur != NULL; cur = cur->next)
	{
		if (cur->data == value)
			return cur;
	}
	return NULL;
}

void LinkListInsertBack(LinkNode * pos, LinkType value)
{
	if (pos == NULL)
		return;
	LinkNode * NewNode = CreateNewNode(value);
	NewNode->next = pos->next;
	pos->next = NewNode;
	return;
}

void LinkListInsertBefo(LinkNode ** head, LinkNode * pos, LinkType value)
{
	if (head == NULL)
		return;
	if (*head == NULL)
		return;
	if (pos == NULL)
		return; 
	LinkNode *NewNode = CreateNewNode(value);
	NewNode->next = pos->next;
	pos->next = NewNode;
	NewNode->data = pos->data;
	pos->data = value;
	return;
}

void LinkListDelVal(LinkNode ** head, LinkType value)
{
	if (head == NULL || *head == NULL)
		return;
	LinkNode *cur;
	if ((*head)->data == value)
	{
		LinkListPopHead(head);
	}
	LinkNode * pos = FindPrevious(*head, value);
	while (!IsLast(*head, pos))
	{
		cur = pos->next;
		pos->next = cur->next;
		DestroyNode(cur);
		pos = FindPrevious(*head, value);
	}
}

int IsLast(LinkNode * head,LinkNode* pos)
{
	return pos->next == NULL;
}

LinkNode * FindPrevious(LinkNode * head, LinkType value)
{
	LinkNode *p = head;
	while (p->next != NULL && p->next->data != value)
	{
		p = p->next;
	}
	return p;
}

void LinkListPopBack(LinkNode ** head)
{
	if (head == NULL)
		return;
	if (*head == NULL)
		return;
	if ((*head)->next == NULL)
	{
		DestroyNode(*head);
		*head = NULL;
		return;
	}
	LinkNode * pre = NULL;
	LinkNode * cur = *head;
	while (cur->next)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	DestroyNode(cur);
	return;
}

//修改元素
void LinkListChange(LinkNode * head, LinkType previous, LinkType After)
{
	LinkNode * cur = head;
	while (cur != NULL)
	{
		if (cur->data == previous)
		{
			cur->data = After;
		}
		cur = cur->next;
	}
	return;
}

//删除链表
void LinkListDelete(LinkNode ** head)
{
	if (head == NULL)
		return;
	if (*head == NULL)
		return;
	LinkNode *p = NULL;
	while (*head != NULL)
	{

		p = (*head)->next;
		PrintChar(*head, "****************删除链表**************\n");
		DestroyNode(*head);
		*head = p;
	}
	return;
}

//链表长度
int LinkListSize(LinkNode * head)
{
	if (head == NULL)
		return 0;
	LinkNode * cur = head;
	int count = 0; 
	while (cur)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

void TestInit()
{
	LinkNode * head;
	LinkListInit(&head);
}

//尾插测试
void TestLinkListPushBack()
{
	LinkNode * head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	LinkListPushBack(&head, 'e');
	PrintChar(head, "*****尾插元素****");
}

//TEST
void TestSize() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'c');
	size_t ret = LinkListSize(head);
	printf("szie = %d\n", ret);
}

//尾删元素
void TestLinkListPopBack() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	PrintChar(head, "****************尾插四个元素**************");
	LinkListPopBack(&head);
	PrintChar(head, "****************尾删一个元素**************");
}

//测试头插一个元素
void TestLinkListPushHead() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushHead(&head, 'd');
	LinkListPushHead(&head, 'c');
	LinkListPushHead(&head, 'b');
	LinkListPushHead(&head, 'a');
	PrintChar(head, "****************头插四个元素**************");
}

//测试头删一个元素
void TestLinkListPopHead()
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushHead(&head, 'd');
	LinkListPushHead(&head, 'c');
	LinkListPushHead(&head, 'b');
	LinkListPushHead(&head, 'a');
	PrintChar(head, "****************头插四个元素**************");
	LinkListPopHead(&head);
	PrintChar(head, "****************头删一个元素**************");
}
//测试在pos下标后插入值
void TestLinkListInsert() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushHead(&head, 'd');
	LinkListPushHead(&head, 'c');
	LinkListPushHead(&head, 'b');
	LinkListPushHead(&head, 'a');
	PrintChar(head, "****************头插四个元素**************");
	LinkNode* pos = head->next;
	LinkListInsertBack(pos, 'd');
	PrintChar(head, "************插入一个元素******************");
}


//测试查找一个元素
void TestLinkListFind() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	PrintChar(head, "****************尾插四个元素**************");
	LinkNode* pos = LinkListFind(head, 'a');
	printf("pos except %p,actual %p\n", head->next, pos);
	PrintChar(head, "****************查找元素**************");

}

//测试在pos下标前插入一个元素
void TestLinkListInsertBef() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	PrintChar(head, "****************尾插四个元素**************");
	LinkNode* pos = LinkListFind(head, 'd');
	LinkListInsertBefo(&head, pos, 'x');
	PrintChar(head, "********************在d之前插入**********");
}

//删除元素
void TestLinkListDelVal() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	PrintChar(head, "****************尾插四个元素**************");
	LinkListDelVal(&head, 'b');
	PrintChar(head, "****************删除元素c*****************");
}

//测试删除所有的a元素
void TestLinkListDelAll()
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'a');

	PrintChar(head, "****************尾插七个元素**************");
	LinkListDelVal(&head, 'a');
	PrintChar(head, "****************删除所有的a元素**************");
}

//删除链表
void TestLinkListDelList()
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'a');

	PrintChar(head, "****************尾插七个元素**************");
	LinkListDelete(&head);
	PrintChar(head, "****************删除链表**************");
}

//测试修改元素的值
void TestLinkListChange()
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'a');

	PrintChar(head, "****************尾插七个元素**************");
	LinkListChange(head,'a', 'e');
	PrintChar(head, "*************修改所有的a元素为e***********");
}

int main(int argc, char * argv[])
{

	//TestLinkListPushBack();
	//TestSize();
	//TestLinkListPopBack();
	//TestLinkListPushHead();
	//TestLinkListPopHead();
	//TestLinkListInsert();	
	//TestLinkListFind();
	//TestLinkListInsertBef();
	//TestLinkListDelVal();	
	//TestLinkListDelAll();
	TestLinkListDelList();
	system("pause");
	return 0;
}
