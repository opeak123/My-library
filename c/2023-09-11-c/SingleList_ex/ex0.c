#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

//����ü ����
typedef struct Node
{
	char nData[64];
	struct Node* next;

}Node;

//��� ��� ����
Node* g_head;

int InsertNode(char* newData)
{
	//��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));



	if (newNode == NULL)
		return 0;


	//�޸� �ʱ�ȭ
	memset(newNode,0,sizeof(Node));
	//����
	strcpy_s(newNode->nData, sizeof(newNode->nData), newData);
	

	if (g_head == NULL)
	{
		g_head = newNode;
	}
	else
	{
		newNode->next = g_head; //�����ڵ�(����)
		//g_head->next = newNode->nData; Ʋ�� (�����ۼ��Ѱ�)
		g_head = newNode; //�����ڵ�(����)
	}
	return 1;
}



int main()
{

	InsertNode("sad");
	//PrintList();
	return 0;
}