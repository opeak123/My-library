#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

// 0  1
#define IS_EMPTY(g_head) (!(g_head))

typedef struct Node* node_Pointer;

typedef struct Node
{
	char nData[10];
	node_Pointer next;
}Node;

Node* g_head = NULL;


void InsertNewNode(char* getData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));
	strcpy_s(newNode->nData, sizeof(newNode->nData), getData);

	if (IS_EMPTY(g_head) == 1)
	{
		g_head = newNode;
	}
	else
	{
		newNode->next = g_head;
		g_head = newNode;
	}
}

void PrintNode()
{
	Node* pNode = g_head;

	while (IS_EMPTY(pNode) == 0)
	{
		//�� �ּҰ� ����Ű�� ������ ---> :
		//�� �����ּ� --->
		printf("[%p]�� �ּҰ� ����Ű�� ������ ---> [%s]\n", pNode, pNode->nData);
		printf("[%p]�� ���� �ּ� ---> [%p]\n\n", pNode, pNode->next);
		pNode = pNode->next;
	}
}

void DeleteNode(char* getData)
{
	Node* pTemp = g_head;
	Node* pDelete = pTemp;
	int foundNode = NULL;

	while (pTemp != NULL)
	{
		pDelete = pTemp;
		pTemp = pTemp->next;

		if (strcmp(pDelete->nData, getData) == 0)
		{
			// ~�� �����Ͱ� �����Ǿ���
			printf("%s�� �����Ͱ� �����Ǿ���\n", getData);
			free(pDelete);
			foundNode++;
			break;
		}
	}
	if (foundNode == NULL)
	{
		printf("%s�� �����͸� ã�� �� ����\n", getData);
	}
}

int main()
{

	InsertNewNode("Test01");
	InsertNewNode("Test02");
	InsertNewNode("Test03");

	//DeleteNode("Test03");
	PrintNode();



	return 0;
}