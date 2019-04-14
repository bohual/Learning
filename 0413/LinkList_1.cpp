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

//�޸�Ԫ��
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

//ɾ������
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
		PrintChar(*head, "****************ɾ������**************\n");
		DestroyNode(*head);
		*head = p;
	}
	return;
}

//������
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

//β�����
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
	PrintChar(head, "*****β��Ԫ��****");
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

//βɾԪ��
void TestLinkListPopBack() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	PrintChar(head, "****************β���ĸ�Ԫ��**************");
	LinkListPopBack(&head);
	PrintChar(head, "****************βɾһ��Ԫ��**************");
}

//����ͷ��һ��Ԫ��
void TestLinkListPushHead() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushHead(&head, 'd');
	LinkListPushHead(&head, 'c');
	LinkListPushHead(&head, 'b');
	LinkListPushHead(&head, 'a');
	PrintChar(head, "****************ͷ���ĸ�Ԫ��**************");
}

//����ͷɾһ��Ԫ��
void TestLinkListPopHead()
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushHead(&head, 'd');
	LinkListPushHead(&head, 'c');
	LinkListPushHead(&head, 'b');
	LinkListPushHead(&head, 'a');
	PrintChar(head, "****************ͷ���ĸ�Ԫ��**************");
	LinkListPopHead(&head);
	PrintChar(head, "****************ͷɾһ��Ԫ��**************");
}
//������pos�±�����ֵ
void TestLinkListInsert() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushHead(&head, 'd');
	LinkListPushHead(&head, 'c');
	LinkListPushHead(&head, 'b');
	LinkListPushHead(&head, 'a');
	PrintChar(head, "****************ͷ���ĸ�Ԫ��**************");
	LinkNode* pos = head->next;
	LinkListInsertBack(pos, 'd');
	PrintChar(head, "************����һ��Ԫ��******************");
}


//���Բ���һ��Ԫ��
void TestLinkListFind() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	PrintChar(head, "****************β���ĸ�Ԫ��**************");
	LinkNode* pos = LinkListFind(head, 'a');
	printf("pos except %p,actual %p\n", head->next, pos);
	PrintChar(head, "****************����Ԫ��**************");

}

//������pos�±�ǰ����һ��Ԫ��
void TestLinkListInsertBef() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	PrintChar(head, "****************β���ĸ�Ԫ��**************");
	LinkNode* pos = LinkListFind(head, 'd');
	LinkListInsertBefo(&head, pos, 'x');
	PrintChar(head, "********************��d֮ǰ����**********");
}

//ɾ��Ԫ��
void TestLinkListDelVal() 
{
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head, 'a');
	LinkListPushBack(&head, 'b');
	LinkListPushBack(&head, 'c');
	LinkListPushBack(&head, 'd');
	PrintChar(head, "****************β���ĸ�Ԫ��**************");
	LinkListDelVal(&head, 'b');
	PrintChar(head, "****************ɾ��Ԫ��c*****************");
}

//����ɾ�����е�aԪ��
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

	PrintChar(head, "****************β���߸�Ԫ��**************");
	LinkListDelVal(&head, 'a');
	PrintChar(head, "****************ɾ�����е�aԪ��**************");
}

//ɾ������
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

	PrintChar(head, "****************β���߸�Ԫ��**************");
	LinkListDelete(&head);
	PrintChar(head, "****************ɾ������**************");
}

//�����޸�Ԫ�ص�ֵ
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

	PrintChar(head, "****************β���߸�Ԫ��**************");
	LinkListChange(head,'a', 'e');
	PrintChar(head, "*************�޸����е�aԪ��Ϊe***********");
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
