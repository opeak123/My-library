//#include <stdio.h>
//#include <string.h>
//#include <memory.h>
//#include <malloc.h>
//
//
//#define IS_EMPTY(g_head) (!(g_head))
//
//typedef struct Node* node_pointer;
//
//typedef struct Node
//{
//	char nData[64];
//	node_pointer next;
//}Node;
//
//Node* g_head = NULL;
//
//
//void InsertNewNode(char* getData)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	memset(newNode, 0, sizeof(Node));
//	strcpy_s(newNode->nData, sizeof(newNode->nData), getData);
//
//	if (IS_EMPTY(g_head) == 1)
//	{
//		g_head = newNode;
//	}
//	else
//	{
//		newNode->next = g_head;
//		g_head = newNode;
//	}
//}
//
//void PrintNode(void)
//{
//	Node* pNode = g_head;
//
//	while (IS_EMPTY(pNode) == 0)
//	{
//		//%p�� �ּҰ� ����Ű�°��� ������ --->  %s 
//		//%s �������� ���� �ּ� ---> %p 
//		printf("%p�� �ּҰ� ����Ű�°��� ������ --->  %s\n",
//			pNode,pNode->nData);
//
//		printf("%s �������� ���� �ּ� ---> %p\n\n",
//			pNode->nData, pNode->next);
//		pNode = pNode->next;
//	}
//}
//
//void DeleteNode(char* getData)
//{
//	Node* pTemp = g_head;
//	Node* pDelete = pTemp;
//
//	int foundNode = NULL;
//
//	if (pTemp == NULL)
//		printf("������ ��尡 ����");
//
//	while (pTemp != NULL)
//	{
//		pDelete = pTemp;
//		pTemp = pTemp->next;
//
//		if (strcmp(pTemp->nData, getData) == 0)
//		{
//			printf("%s�� ��尡 �����Ǿ���\n", pTemp->nData);
//			free(pDelete);
//			foundNode++;
//			break;
//		}
//
//		if (foundNode == NULL)
//		{
//			printf("%s�� �����͸� ã�� �� ����\n", getData);
//			break;
//		}
//	}
//}
//
//int main()
//{
//	InsertNewNode("Test01");
//	InsertNewNode("Test02");
//
//	PrintNode();
//
//	DeleteNode("Test0331");
//	PrintNode();
//
//
//	return 0;
//}