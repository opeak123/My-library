//#include <stdio.h>
//
//
//
//typedef struct Node
//{
//	//������ ������(����)
//	int nData;
//
//
//	//������ ������ ���� ������
//	struct Node* next;
//}Node;
//
//
//
//int main()
//{
//	Node list[5] = { 0 };
//	//����ü 5��
//
//
//	list[0].next = &list[1];
//	list[1].next = &list[2];
//	list[2].next = &list[3];
//	list[3].next = &list[4];
//	list[4].next = 0;
//
//
//
//	list[0].nData = 100;
//	list[1].nData = 200;
//	list[2].nData = 300;
//	list[3].nData = 400;
//	list[4].nData = 500;
//
//
//	printf_s("%d", list[1].nData); // 200
//
//	Node* pTmp = &list[0];
//	while (true)
//	{
//
//	}
//
//	//���Ḯ��Ʈ �ܼ��ϰ� �����شٸ� �̷��� �ۼ��ϸ� �� 
//	return 0;
//}