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

int PrintNode()
{
	Node* pNode = g_head;

	if (IS_EMPTY(pNode) == 1)
	{
		printf("��尡 ����\n");
		return 1;
	}

	while(IS_EMPTY(pNode) == 0)//0
	{
		printf("[%p]�� �ּҰ� ����Ű�� ������ ---> [%s]\n", pNode, pNode->nData);
		printf("[%p]�ּ��� ���� ---> [%p]\n\n", pNode, pNode->next);

		pNode = pNode->next;
	}
	return 0;
}

/*int DeleteNode(char* getData)
{
	Node* pTemp = g_head;
	Node* pDelete = pTemp;
	 int cmpCount = 0;

	if (IS_EMPTY(g_head) == 1)
	{
		printf("DeleteData() : ������ ��� ����\n");
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

	if (cmpCount == NULL)
	{
		printf("DeleteData() : �����͸� ã�� �� ����\n");
		return 1;
	}
}*/

int DeleteNode(char* getData)
{
	Node* pTemp = g_head;
	Node* pPrev = NULL;
	int cmpCount = 0;

	if (IS_EMPTY(g_head) == 1)
	{
		printf("DeleteData() : ������ ��� ����\n");
		return 1;
	}

	while (pTemp != NULL)
	{
		if (strcmp(pTemp->nData, getData) == 0)
		{
			if (pPrev != NULL)
			{
				pPrev->next = pTemp->next;
			}
			else
			{
				g_head = pTemp->next;
			}

			printf("DeleteData() : [%s]�� �����Ͱ� �����Ǿ���\n", getData);
			free(pTemp);
			cmpCount++;
			break;
		}

		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if (cmpCount == 0)
	{
		printf("DeleteData() : �����͸� ã�� �� ����\n");
		return 1;
	}

	return 0;
}

int SearchNode(char* getData)
{
	Node* sNode = g_head;
	int cmpCount = 0;

	if (IS_EMPTY(sNode) == 1)
	{
		printf("SearchNode() : ��尡 ����\n");
		return 1;
	}

	while (sNode != NULL)
	{
		if (strcmp(sNode->nData, getData) == 0)
		{
			printf("[%s]�� ã�� ---> �ּ� : [%p] \n",sNode->nData,sNode);
			cmpCount++;
			break;
		}
		sNode = sNode->next;
	}

	if (cmpCount == NULL)
	{
		printf("SearchNode() : [%s]�� ã�� �� ����\n", getData);		
		return 1;
	}
	return 0;
}

int main()
{
	InsertNewNode("Test01");

	DeleteNode("Test01");

	InsertNewNode("Test02");
	InsertNewNode("Test03");

	PrintNode();

	SearchNode("Test01");



	return 0;
}