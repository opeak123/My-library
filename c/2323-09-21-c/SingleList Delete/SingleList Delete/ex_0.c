#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

#define IS_EMPTY(g_head) (!(g_head))

typedef struct Node* node_Pointer;
typedef struct Node
{
	char nData[50];
	node_Pointer next;

}Node;

Node* g_head = NULL;


//��� ���� ���� 

void InsertNewNode(char* getData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode,0,sizeof(Node));
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

void PrintNode(void)
{
	Node* pNode = g_head;

	while (IS_EMPTY(pNode) == 0)
	{
		// ~ �� �ּ� ������ ---> %s
		// %�� �ּ��� �����ּ� ---> %p
		printf("[%p]�� ������ ----> [%s]\n", pNode, pNode->nData);
		printf("[%p]�� �����ּ� ---> [%p]\n\n", pNode, pNode->next);
		pNode = pNode->next;
	}
}

int DeleteNode(char* getData)
{
	Node* pTemp = g_head;
	Node* pDelete = pTemp;
	int cmpCount = NULL;

	if (IS_EMPTY(g_head) == 1)
	{
		printf("DeleteData() : ������ ��尡 ����\n");
		return 1;
	}

	while (pTemp != NULL)
	{
		pDelete = pTemp;
		pTemp = pTemp->next;
		
		if (strcmp(pDelete->nData, getData) == 0)
		{
			printf("DeleteData() : [%s]�� �����Ͱ� �����Ǿ���\n", getData);
			free(pDelete);
			cmpCount++;
			break;
		}
	}

	if (cmpCount == 0)
	{
		printf("DeleteData() : �����͸� ã�� �� ����\n");
		return 1;
	}

}


int main()
{
	InsertNewNode("Test01");
	InsertNewNode("Test02");
	InsertNewNode("Test03");

	PrintNode();
	DeleteNode("Test01");
	PrintNode();

	return  0;
}