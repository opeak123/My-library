//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct NODE
//{
//    char szData[64];
//    struct NODE* next;
//} NODE;
//
//NODE* g_pHead = NULL;	// ��� ���
//
///* ���� ����Ʈ ��ü ����Ʈ ��� �Լ� */
//void PrintList(void)
//{
//    NODE* pHead = g_pHead;
//
//    while (pHead != NULL)
//    {
//        printf("[%p] %s, next[%p]\n", pHead, pHead->szData, pHead->next);
//        pHead = pHead->next;
//    }
//    printf("\n");
//}
//
///* �պκп� �� ��� �߰� �Լ� */
//int InsertNewNode(char* pszData)
//{
//    NODE* pNode = (NODE*)malloc(sizeof(NODE));
//    if (pNode == NULL)
//        return 0;
//    memset(pNode, 0, sizeof(NODE));
//    strcpy_s(pNode->szData, sizeof(pNode->szData), pszData);
//
//    if (g_pHead == NULL)
//        g_pHead = pNode;
//    else
//    {
//        pNode->next = g_pHead;
//        g_pHead = pNode;
//    }
//
//    return 1;
//}
//
///* ���� ����Ʈ ��ü ����Ʈ ���� */
//void ReleaseList(void)
//{
//    NODE* pTmp = g_pHead;
//
//    while (pTmp != NULL)
//    {
//         //�ݺ��� ������ ���� �����ϴ� ���� �������� �ֱٿ��� �ָ���
//         //�����Ϸ��� ����ȭ�� �� ���ֱ� ����
//         //������ ���ټ� �������� �Ϻη� �ϴ� ��쵵 ����
//        NODE* pDelete = pTmp;
//        pTmp = pTmp->next;
//
//        printf("Delete: [%p] %s\n", pDelete, pDelete->szData);
//        free(pDelete);
//    }
//}
//
///* Ư�� ��带 �����ϴ� �� Ȯ���ϴ� �Լ� */
//int FindData(char* pszData)
//{
//    NODE* pTmp = g_pHead;
//    while (pTmp != NULL)
//    {
//        if (strcmp(pTmp->szData, pszData) == 0)
//            return 1;
//        pTmp = pTmp->next;
//    }
//
//    return 0;
//}
//
///* Ư�� ��带 ã�� �����ϴ� �Լ�*/
//int DeleteData(char* pszData)
//{
//    NODE* pTmp = g_pHead;
//    NODE* pPrev = NULL;
//    while (pTmp != NULL)
//    {
//        if (strcmp(pTmp->szData, pszData) == 0)
//        {
//             //����
//            if (pPrev != NULL)
//                pPrev->next = pTmp->next;
//            else
//            {
//                 //������ �����Ͱ� ù ��°
//                g_pHead = pTmp->next;
//            }
//            free(pTmp);
//            return 1;
//        }
//        pPrev = pTmp;
//        pTmp = pTmp->next;
//    }
//
//    return 0;
//}
//
//int main(void)
//{
//     //List �׽�Ʈ�� ���� �ڵ�
//    InsertNewNode("TEST01");
//    PrintList();
//    InsertNewNode("TEST02");
//    PrintList();
//    InsertNewNode("TEST03");
//    PrintList();
//
//    if (FindData("TEST01") == 1)
//        printf("FindData(): TEST01 found\n");
//    if (FindData("TEST02") == 1)
//        printf("FindData(): TEST02 found\n");
//    if (FindData("TEST03") == 1)
//        printf("FindData(): TEST03 found\n");
//    putchar('\n');
//
//    DeleteData("TEST03");
//    PrintList();
//    DeleteData("TEST02");
//    PrintList();
//    DeleteData("TEST01");
//    PrintList();
//
//    ReleaseList();
//
//    return 0;
//}