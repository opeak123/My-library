#include <stdio.h> //index
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

//����
//���� 
//�˻�
//���

typedef struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
} Tree;

Tree* InsertNode(Tree* t, int value);
void PrintNode(Tree* t);
Tree* SearchNode(Tree* t, int target);
Tree* GetMaxNode(Tree* t);
Tree* GetMinNode(Tree* t);


int main(void)
{
	Tree* root = NULL;
	int choice;
	int data;
	Tree* findNode;

	while (1)
	{
		system("cls");
		printf("\n\n\t\t Binary Search Tree(BST)\n\n\n");
		printf("1 ��� ����\n");
		printf("2 ��� ����\n");
		printf("3 ��� �˻�\n");
		printf("4 �ִ� ���ϱ�\n");
		printf("5 �ּڰ� ���ϱ�\n");
		printf("6 ���� �˻� Ʈ�� ���(������ȸ)\n");
		printf("0 ���α׷� ����\n");
		printf("\n�޴�����: ");
		scanf("%d", &choice);

		while (getchar() != '\n');

		switch (choice)
		{
		case 1:
			printf("\n\n������ ���� �Է�: ");
			scanf("%d", &data);
			root = InsertNode(root, data);
			break;

		case 2:

			break;

		case 3:
			printf("\n\n�˻��� ���� �Է� : ");
			scanf("%d", &data);

			findNode = SearchNode(root, data);

			if(findNode == NULL)
			{
				printf("\n\n\t\t�˻��� ���� �������� �ʽ��ϴ�.\n");
			}
			else
			{
				printf("\n\n\t\t�˻��� ���� �����մϴ�.\n");
			}
			break;

		case 4:
			findNode = GetMaxNode(root);
			if (findNode != NULL)
			{
				printf("\n\n\t\t �ִ��� %d�Դϴ�/ \n", findNode->data);
			}
			break; 

		case 5:
			findNode = GetMinNode(root);
			if (findNode != NULL)
			{
				printf("\n\n\t\t �ּڰ��� %d�Դϴ�/ \n", findNode->data);
			}
			break;

		case 6:
			printf("������ȸ ���(��������): ");
			PrintNode(root);
			printf("\n");
			break;

		case 0:
			exit(0);

		default:
			break;
		}

		printf("\n\n\t\t");
		system("pause");
	}

	return 0;
}

Tree* InsertNode(Tree* t, int value)
{
	if (t == NULL)
	{
		t = (Tree*)calloc(1, sizeof(Tree));
		t->data = value;
		t->left = NULL;
		t->right = NULL;
	}
	else if (t->data == value)
	{
		printf("error: ���� ���� �̹� �����մϴ�.\n");
	}
	else if (t->data > value)
	{
		t->left = InsertNode(t->left, value);
	}
	else
	{
		t->right = InsertNode(t->right, value);
	}

	return t;
}

void PrintNode(Tree* t)
{
	if(t != NULL)
	{
		PrintNode(t->left);
		printf("%d ", t->data);
		PrintNode(t->right);
	}
}

Tree* SearchNode(Tree* t, int target)
{
	if (t == NULL)
	{
		return NULL;
	}

	if (t->data == target)
	{
		return t;
	}
	else if (t->data > target)
	{
		return SearchNode(t->left, target);
	}
	else//(t->data < target)
	{
		return SearchNode(t->right, target);
	}
}

Tree* GetMaxNode(Tree* t)
{
	if (t == NULL)
	{
		return NULL;
	}

	if (t->right != NULL)
	{
		return GetMaxNode(t->right);
	}
	return t; //�ִ� ��� ����
}

Tree* GetMinNode(Tree* t)
{
	if (t == NULL)
	{
		return NULL;
	}

	if (t->left != NULL)
	{
		return GetMinNode(t->left);
	}
	return t; //�ּڰ� ��� ����
}
