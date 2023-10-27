#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>

//��� ���� Ȯ���� ���ù� ����
#define IS_EMPTY(g_head) (!(g_head))

//�ʱ�ȭ
void InitNode();
//����
void InsertAtHead(const char* getData); //���
void InsertAtTail(const char* getData); //����
//����
int DeleteNode(const char* getData);
//ã��
int SearchNode(const char* getData);
//���
int PrintNode();


//����ü ��� �� ������ ����
typedef struct Node* node_pointer;
typedef struct Node
{
	char* nData;
	node_pointer next;
	node_pointer prev;
}Node;

//���,���� �ʱ�ȭ
Node* g_head = NULL;
Node* g_tail = NULL;

//��� ���� Ȯ���� ���� ����
int g_nodeCount = 0;


//���,���� ��� ���� �� �޸� �ʱ�ȭ
void InitNode(void)
{
	g_head = (Node*)malloc(sizeof(Node));
	g_tail = (Node*)malloc(sizeof(Node));
	g_nodeCount = 0;

	memset(g_head, 0, sizeof(Node));
	memset(g_tail, 0, sizeof(Node));

	g_head->next = g_tail->prev;	
	g_tail->prev = g_head->next;
	//g_head->next = g_tail;
}

void InsertAtHead(const char* getData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));

	///
	newNode->next = g_head->next;
	newNode->prev = g_head;

	g_head->next = newNode;
	newNode->next->prev = newNode;///

	return 0;
}

void InsertAtTail(const char* getData)
{
}

//��� ����
int DeleteNode(const char* getData)
{
	Node* temp = g_head;
	Node* del = temp;
	int cmpCount = 0;

	if (IS_EMPTY(temp) == 1)
	{
		printf("DeleteNode() : head is empty -> \n");
		return 1;
	}

	while (temp != NULL)
	{
		//���ڿ� ��
		if (strcmp(temp->nData, getData) == 0)
		{
			//�޸� ����
			free(temp);
			cmpCount++;
			printf("DeleteNode() : deleted -> %s\n",getData);
			break;
		}
		//���� ��� ����
		del = temp;
		temp = temp->next;
	}

	if (cmpCount == 0)
	{
		printf("DeleteNode() : can't find -> %s\n", getData);
		return 1;
	}

	return 0;
}

//��� ���
int PrintNode()
{
	Node* temp = g_head;

	if (IS_EMPTY(temp) == 1)
	{
		printf("PrintNode() : head is empty\n");
		return 1;
	}
	
	do
	{
		printf("PrintNode() :");
		printf("nodeCount :%s\n", g_nodeCount);
		printf("%p's data -> %s\n\n", temp, temp->nData);
		g_nodeCount++;
		temp = temp->next;
	}
	while (temp != NULL);

	return 0;
}


int main(void)
{
	InitNode();
	return 0;
}