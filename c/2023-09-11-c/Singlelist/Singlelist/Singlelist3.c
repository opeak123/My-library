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
//int main(){	Node list[5] = { 0 };
//	//����ü 5��
//
//	list[0].nData = 100;
//	list[1].nData = 200;
//	list[2].nData = 300;
//	list[3].nData = 400;
//	list[4].nData = 500;
//
//
//	list[0].next = &list[4]; 
//	list[1].next = &list[2]; 
//	list[2].next = &list[3]; 
//	list[3].next = &list[0];
//	list[4].next = &list[1];
//	   
//	// list[0] -> list[4] -> list[1] -> list[2] -> list[3] ->
//	// 100-> 500 -> 200 -> 300 ->  400  
//	// -> 500 -> 200 -> 300 -> 400 -> 500 ->
//
//
//	// 100 -> 500 -> 200 -> 300 -> 400
//
//	//100 -> 500 -> 200 -> 300 -> 400 -> 100 -> 500 -> 200 ->
//	// 300 ->
//
//	// 300 -> 400 -> 100 -> 500 -> 200 -> 300 -> 400 -> 
//	//100 -> 
//
//
//	for(int i=0; i< 5; ++i)
//		printf_s("list[%d]: %d\n", i,list[i].nData);
//
//	Node* pTmp = &list[4];
//	while (pTmp != NULL)
//	{		printf_s("%p: %d\n",pTmp,pTmp -> nData);
//		pTmp = pTmp->next;
//	}
//
//
//	return 0;
//}