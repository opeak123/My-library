//#include <stdio.h>
//#include <malloc.h>
//#include <memory.h>
//#include <string.h>
//
////����ü ����
//typedef struct Node
//{
//	char nData[64];
//	struct Node* next;
//
//}Node;
//
////��� ��� ����
//Node* g_head;
//
//int InsertNode(char* newData)
//{
//	//��� ����
//	Node* newNode = (Node*)malloc(sizeof(Node));
//
//
//
//	if (newNode == NULL)
//		return 0;
//
//
//	//�޸� �ʱ�ȭ
//	memset(newNode,0,sizeof(Node));
//	//����
//	strcpy_s(newNode->nData, sizeof(newNode->nData), newData);
//	//strncpy_s(newNode->nData, sizeof(newNode->nData), newData, _TRUNCATE);
//	// strncpy_s�� ����ũ�⸦ �°� �ڸ��ų� �����Ҷ�
//
//	if (g_head == NULL)
//	{
//		g_head = newNode;
//	}
//	else
//	{
//		newNode->next = g_head;
//		g_head = newNode; //���� �ٲٸ� ������ ����
//	} 
//	return 1; 
//}
//
//void PrintNode(void)
//{ 
//	Node* p_head = g_head;
//	while (p_head != NULL)
//	{
//		printf("[�ּҰ�: %p�� ����ִ� ������ : %s] = ", p_head, p_head->nData);
//		printf("[���� next�� : %p]\n", p_head->next);
//		p_head = p_head->next;
//
//	}
//	putchar('\n');
//}
//
//
//int main()
//{
//
//	InsertNode("sad");
//	//PrintNode();
//
//	InsertNode("happy");
//	PrintNode();
//	return 0;
//}