#include <stdio.h>
#include <string.h>
#include <memory.h>

typedef struct Node* nodePointer;

typedef struct Node
{
	char* nData;
	nodePointer next;
	nodePointer prev;

}Node;

Node* g_head = NULL;
Node* g_tail = NULL;

int nodeLength;


//��� �ʱ�ȭ
void InitNode();

//��� ����
void InsertAtHead();
void InsertAtTail();

//��� �˻�
void SearchNode();

//��� ����
void DeleteNode();

//��� �� ��ȯ
void GetLength();


int main(void)
{
	 

	return 0;
}