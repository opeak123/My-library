//#include <stdio.h>
//#include <stdlib.h> //malloc.h
//#include <string.h> //memory.h
////#include <tchar.h>
//
//typedef struct Node
//{
//
//	char szData[64];
//	struct Node* next;
//
//}Node;
//
//Node* g_pHead = NULL;
//
//
//
////���� ����Ʈ ��ü ������ ���
//void PrintList(void)
//{
//	Node* pHead = g_pHead;
//	while (pHead != NULL)
//	{
//		printf_s("[%p] %s, next[%p]\n",
//			pHead, pHead->szData, pHead->next);
//		pHead = pHead->next;
//	}
//	putchar('\n');
//}
//
//int InsertNewNode(char* pszData)
//{
//	Node* pNode = (Node*)malloc(sizeof(Node));
//	memset(pNode,0, sizeof(Node));
//
//	strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);
//	
//
//	if (g_pHead == NULL)
//	{
//		g_pHead = pNode;
//	}
//	else
//	{
//		pNode->next = g_pHead;
//		g_pHead = pNode;
//
//	}
//
//	return 1;
//}
//
//int main()
//{
//
//	//List �׽�Ʈ�� ���� �ڵ� 
//	InsertNewNode("Test01");
//	PrintList();
//	InsertNewNode("Test02");
//	PrintList();
//	InsertNewNode("Test03");
//	PrintList();
//	return 0;
//}
//
//
//
////memset ����
//// 
////������� ���̵�
//// �迭 "blockdmask blog"���� ���ڸ� 5�ڸ���
//// 'c' ������ �ʱ�ȭ �� ���� �� �� �ֽ��ϴ�.
//
////#include<string.h> // #include<memory.h> �� �������ϴ�.
////#include<stdio.h>
////
////int main(void)
////{
////	char arr1[] = "blockdmask blog";
////	memset(arr1, 'c', 5 * sizeof(char));
////	printf(arr1);
////
////	return 0;
////}