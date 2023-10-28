#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>

//��� ���� Ȯ���� ���ù� ����
#define IS_EMPTY(g_head) (!(g_head))

//�ʱ�ȭ
void InitNode();
//����
int InsertAtHead(const char* getData); //���
int InsertAtTail(const char* getData); //����
//����
int DeleteNode(const char* getData);
//ã��
int SearchNode(const char* getData);
//���
int PrintNode();


//����ü ��� �� ������ ����
typedef struct Node* node_pointer;
typedef struct Node
{
	char* nData;
	node_pointer next;
	node_pointer prev;
}Node;

//���,���� �ʱ�ȭ
Node* g_head = NULL;
Node* g_tail = NULL;

//��� ���� Ȯ���� ���� ����
int g_nodeCount;


//���,���� ��� ���� �� �޸� �ʱ�ȭ
void InitNode(void)
{
	//���,���� �޸� �Ҵ�
	g_head = (Node*)malloc(sizeof(Node));
	g_tail = (Node*)malloc(sizeof(Node));

	//�ʱ�ȭ
	g_nodeCount = 1;
	memset(g_head, 0, sizeof(Node));
	memset(g_tail, 0, sizeof(Node));

	//��� ��ġ ����
	g_head->nData = "HEAD";
	g_tail->nData = "TAIL";

	g_head->next = g_tail;
	g_tail->prev = g_head;
}

int InsertAtHead(const char* getData)
{
    // ...
    //���,���ϳ�� �� ��忡 ����
    g_head->next = newNode;
    newNode->next->prev = newNode;
    return 0;
}

int InsertAtTail(const char* getData)
{
    // ...
    //�� ��带 tail�� prev�� ����
    g_tail->prev->next = newNode;
    g_tail->prev = newNode;
    return 0;
}

int DeleteNode(const char* getData)
{
    // ...
    while (temp != g_tail)
    {
        //���ڿ� ��
        if (strcmp(temp->nData, getData) == 0)
        {
            // ��� �翬��
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            //�޸� ����
            free(temp);
            cmpCount++;
            printf("DeleteNode() : deleted -> %s
                ", getData);
                break;
        }
        //���� ��� ����
        del = temp;
        temp = temp->next;
    }
    //...
}

int PrintNode()
{
    //��带 ���� ���� ����
    Node* temp = g_head->next;

    //HEAD�� NULL�� ��� RETURN
    if (IS_EMPTY(temp) == 1)
    {
        printf("PrintNode() : head is empty
            ");
            return 1;
    }

    while (temp != g_tail)
    {
        printf("PrintNode() :");
        printf("nodeCount: %d
            ", g_nodeCount);
            printf("%p's data -> %s

                ", temp, temp->nData);
                g_nodeCount++;
        //��� ����
        temp = temp->next;
    }

    return 0;
}



int main(void)
{
	InitNode();
	InsertAtHead("Test01");
	InsertAtHead("Test02");
	InsertAtHead("Test03");


	//InsertAtTail("Test01");
	//InsertAtTail("Test02");
	//InsertAtTail("Test03");
	PrintNode();

	return 0;
}