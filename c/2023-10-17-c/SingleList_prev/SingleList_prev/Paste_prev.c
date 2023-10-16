#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

#define IS_EMPTY(g_head) (!(g_head))

typedef struct Node* node_Pointer;

typedef struct Node
{
	char nData[60];
	node_Pointer next;

}Node,NODE;

Node* g_head = NULL;

void InsertNewNode(char* getData);
void SearchNode(char* getData);
int DeleteNode(char* getData);
int PrintNode();

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

int DeleteNode(char* getData)
{
	Node* pTemp = g_head;
	Node* pPrev = NULL;
	int cmpCount = NULL;

	if (IS_EMPTY(pTemp) == 1)
	{
		printf("DeleteNode() : ������\n");
		return 1;
	}

	while (pTemp != NULL)
	{
		if (strcmp(pTemp->nData, getData) == 0)
		{
			if(pPrev != NULL)
			{
				pPrev->next = pTemp->next;
			}
			else
			{
				g_head = pTemp->next;
			}
			printf("DeleteNode() : %s�� ��������\n", getData);
			free(pTemp);
			cmpCount++;
			break;
		}
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if (cmpCount == NULL)
	{
		printf("DeleteNode() : ������ \n");
		return 1;
	}
}

int PrintNode()
{
	Node* pNode = g_head;

	if (IS_EMPTY(pNode) == 1)
	{
		printf("PrintNode() : ������\n");
		return 1;
	}

	while (pNode != NULL)
	{
		printf("[%p] �ּҰ��� ������ ---> [%s]�� �����ּ� --->[%p]\n", pNode, pNode->nData,pNode->next);
		pNode = pNode->next; 
	}
}


int main() 
{
	//int PrintNode(); C���� ������Ÿ���� �ߺ����� ����
	//DeleteNode = SearchNode �� ���� ��� 
	InsertNewNode("Test01");
	InsertNewNode("Test02");
	InsertNewNode("Test03");
	PrintNode();
	DeleteNode("Test02");
	PrintNode();




	return 0;
}
