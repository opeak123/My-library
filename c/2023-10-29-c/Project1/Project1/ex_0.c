#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>

//��� ���� Ȯ���� ���ù� ����
#define IS_EMPTY(g_head) (!(g_head))

//�ʱ�ȭ
void InitNode();
//����
int InsertAtHead(const char* getData); //���
int InsertAtTail(const char* getData); //����
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
int g_nodeCount;


//���,���� ��� ���� �� �޸� �ʱ�ȭ
void InitNode(void)
{
	//���,���� �޸� �Ҵ�
	g_head = (Node*)malloc(sizeof(Node));
	g_tail = (Node*)malloc(sizeof(Node));

	//�ʱ�ȭ
	g_nodeCount = 1;
	memset(g_head, 0, sizeof(Node));
	memset(g_tail, 0, sizeof(Node));

	//��� ��ġ ����
	g_head->nData = "HEAD";
	g_tail->nData = "TAIL";

	g_head->next = g_tail;
	g_tail->prev = g_head;
}

int InsertAtHead(const char* getData)
{
	//�� ��� �޸� �Ҵ�
	Node* newNode = (Node*)malloc(sizeof(Node));

	//�޸� �ʱ�ȭ
	memset(newNode, 0, sizeof(Node));

	//�����͸� ������ ���� �޸� �Ҵ�
	newNode->nData = (char*)malloc(strlen(getData) + 1);

	//���ڿ� ����
	strcpy_s(newNode->nData, strlen(getData) + 1, getData);

	//�� ��� �� �� ���� 
	newNode->next = g_head->next;
	newNode->prev = g_head;

	//���,���ϳ�� �� ��忡 ����
	g_head->next = newNode;
	newNode->next->prev = newNode;

	return 0;
}

int InsertAtTail(const char* getData)
{
	//�� ��� �޸� �Ҵ�
	Node* newNode = (Node*)malloc(sizeof(Node));

	//�޸� �ʱ�ȭ
	memset(newNode, 0, sizeof(Node));

	//�����͸� ������ ���� �޸� �Ҵ�
	newNode->nData = (char*)malloc(strlen(getData) + 1);

	//���ڿ� ����
	strcpy_s(newNode->nData, strlen(getData) + 1, getData);

	//��� ����
	newNode->next = g_tail;
	newNode->prev = g_tail->prev;

	////�� ��带 tail�� prev�� ����
	//g_head->next = newNode;
	////�� ��带 g_head�� next�� ����
	//newNode->next->prev = newNode;


	//�� ��带 tail�� prev�� ����
	g_tail->prev->next = newNode;
	g_tail->prev = newNode;

	return 0;
}

//��� ����
int DeleteNode(const char* getData)
{
	//��带 ���� ���� ����
	Node* temp = g_head;
	int cmpCount = 0;

	//HEAD�� NULL�� ��� RETURN
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
			//������ ��� ����
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;

			//�޸� ����
			free(temp);
			cmpCount++;
			printf("DeleteNode() : deleted -> %s\n\n", getData);
			break;
		}
		//���� ��� ����
		temp = temp->next;
	}

	//�� �� ���ڿ��� ���� ��� RETURN
	if (cmpCount == 0)
	{
		printf("DeleteNode() : can't find -> %s\n", getData);
		return 1;
	}

	return 0;
}

int SearchNode(const char* getData)
{
	//��带 ���� ���� ����
	Node* temp = g_head;
	int cmpCount = 0;

	//HEAD�� NULL�� ��� RETURN
	if (IS_EMPTY(temp) == 1)
	{
		printf("SearchNode() : head is empty -> \n");
		return 1;
	}

	while (temp != NULL)
	{
		//���ڿ� ��
		if (strcmp(temp->nData, getData) == 0)
		{
			cmpCount++;
			printf("SearchNode() : found -> %s\n\n", getData);
			break;
		}
		//���� ��� ����
		temp = temp->next;
	}

	//�� �� ���ڿ��� ���� ��� RETURN
	if (cmpCount == 0)
	{
		printf("SearchNode() : can't find -> %s\n\n", getData);
		return 1;
	}

	return 0;
}



//��� ���
int PrintNode()
{
	//��带 ���� ���� ����
	Node* temp = g_head;

	//HEAD�� NULL�� ��� RETURN
	if (IS_EMPTY(temp) == 1)
	{
		printf("PrintNode() : head is empty\n");
		return 1;
	}

	do
	{
		printf("PrintNode() :");
		printf("nodeCount: %d\n", g_nodeCount);
		printf("%p's data -> %s\n\n", temp, temp->nData);
		g_nodeCount++;
		//��� ����
		temp = temp->next;
	} while (temp != NULL);

	return 0;
}

int main(void)
{
	InitNode();

	InsertAtTail("tail01");
	InsertAtTail("tail02");
	InsertAtTail("tail03");
	InsertAtHead("head01");
	InsertAtHead("head02");
	InsertAtHead("head03");

	SearchNode("tail03");
	DeleteNode("tail03");
	SearchNode("tail03");


	PrintNode();

	return 0;
}