#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <malloc.h>

#define IS_EMPTY(g_head) (!(g_head))

typedef struct Node* node_Pointer;
typedef struct Node
{
	char nData[50];
	node_Pointer next;
}Node;

Node* g_head = NULL;

void InsertSort(Node* getData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));
	strcpy_s(newNode->nData, sizeof(newNode->nData), getData);


	if (IS_EMPTY(g_head) == 1)
	{
		g_head = newNode;
		newNode->next = NULL;
	}
	else
	{
		Node* nTemp = g_head;
		while (nTemp->next != NULL)
		{
			nTemp = nTemp->next;
		}
		nTemp->next = newNode;
		newNode->next = NULL;
	}
}

void InsertAtHead(Node* getData)
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
void InsertAtTail(char* getData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));
	strcpy_s(newNode->nData, sizeof(newNode->nData), getData);
	newNode->next = NULL;

	if (IS_EMPTY(g_head))
	{
		g_head = newNode; // ����Ʈ�� ������� ���
	}
	else
	{
		Node* tail = g_head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
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

	do
	{
		printf("PrintNode()\n");
		printf("[%p] �ּҰ��� ������ ---> [%s]\n", pNode, pNode->nData);
		printf("[%p]�� ���� �ּ� ---> [%p]\n\n", pNode, pNode->next);

		pNode = pNode->next;
	} 
	while (pNode != NULL);

	return 0;
}

int DeleteNode(char* getData)
{
	Node* dTemp = g_head;
	Node* dPrev = NULL;
	int cmpCount = 0;

	if (IS_EMPTY(dTemp) == 1)
	{
		printf("DeleteNode() : ������\n");
		return 1;
	}

	while(dTemp != NULL)
	{
		if(strcmp(dTemp->nData, getData) == 0)
		{
			if (dPrev != NULL)
			{
				dPrev->next = dTemp->next;
			}
			else
			{
				g_head = dTemp->next;
			}
			printf("DeleteNode() : [%s]�� ������ �Ϸ�\n", getData);
			free(dTemp);
			cmpCount++;
			break;
		}
		dTemp = dTemp->next;
	}

	if(cmpCount == NULL)
	{
		printf("DeleteNode() : [%s]�� ��� ã�� ����\n\n",getData);
		return 1;
	}
}

int SearchNode(char* getData)
{
	Node* sNode = g_head;
	int cmpCount = 0;
	if(IS_EMPTY(sNode) == 1)
	{
		printf("SearchNode() : ������\n");
	}

	while (sNode != NULL)
	{
		if(strcmp(sNode->nData, getData) == 0)
		{
			printf("SearchNode() : [%s]�� ������ ã��\n", getData);
			cmpCount++;
		}
		sNode = sNode->next;
	}

	if (cmpCount == NULL)
	{
		printf("SearchNode() : [%s]�� ��� ã�� ����\n",getData);
		return 1;
	}
	return 0;
}



int main()
{
	/*���� ��� C �����Ϸ������� int�� �����ϰ�
	main �Լ��� �����ϴ� ���� ����� ���� �ֽ��ϴ�. 
	�׷��� �̴� �����Ϸ��� ���� �ٸ� �� ������
	�̽ļ�(�ٸ� �����Ϸ� �� �÷������� ���� ����)�� ������ �� �� �����Ƿ�,
	��Ȯ�ϰ� int main()���� �����ϴ� ���� ���� �����Դϴ�.

	����, main �Լ��� ��ȯ ���� �ü������
	���α׷��� ���� ���¸� �˷��ִ� �߿��� ����̹Ƿ�,
	���α׷��� �ۼ��� �� ��ȯ ���� Ư���� �ǹ̸� �ο��� �� �ֽ��ϴ�.
	�Ϲ������� ���� ����� 0�� ��ȯ�ϰ�, 
	���� �Ǵ� ������ ����� 0�� �ƴ� ���� ��ȯ�մϴ�.*/

	//1.����(head) ,(tail)
	//2.��� 
	//3.����
	//4.ã��

	InsertSort("Sort01");
	InsertAtHead("Test01");
	InsertAtTail("Test04");
	InsertAtHead("Test02");
	InsertAtHead("Test03");
	DeleteNode("Test01");
	SearchNode("Test01");
	SearchNode("Test02");
	PrintNode();

	return 0;
}