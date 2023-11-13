#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct Tree
{
	int value;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* AddNode(Tree* t, int data);
Tree* GetMaxNode(Tree* t);
Tree* GetMinNode(Tree* t);
void DisplayInorder(Tree* t);

int main(void)
{
	Tree* root = NULL;
	Tree* findNode;
	int choice;
	int data;


	while (1)
	{
		system("cls");
		printf("\n\n\t\t Binary Search Tree(BST)\n\n\n");
		printf("1 ��� ���� \n");
		printf("2 ��� ���� \n");
		printf("3 ��� �˻� \n");
		printf("4 �ִ� ���ϱ� \n");
		printf("5 �ּڰ� ���ϱ�\n");
		printf("6 ���� �˻� Ʈ�� ���(������ȸ)\n");
		printf("0 ���α׷� ����\n");
		printf("\n�޴����� : ");
		scanf("%d", &choice);

		while (getchar() != '\n');

		switch (choice)
		{


		case 1:
			printf("\n\n������ ���� �Է� : ");
			scanf("%d", &data);

			root = AddNode(root, data);
			break;

		case 2:
			break;
		case 3:
			break;
		case 4:
			findNode = GetMaxNode(root);
			printf("�ִ� : %d\n", findNode->value);
			break;
		case 5:
			findNode = GetMinNode(root);
			printf("�ּڰ� : %d\n", findNode->value);
			break;
		case 6:
			printf("������ȸ ���(��������) : ");
			DisplayInorder(root);
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

Tree* AddNode(Tree* t, int data)
{
	if (t == NULL)
	{
		t = (Tree*)malloc(sizeof(Tree)); //Ʈ�� ��� ����
		t->value = data;
		t->left = NULL;
		t->right = NULL;
	}
	else if (t->value > data) //������ ������ �� ���� ��� > left��
	{
		t->left = AddNode(t->left, data);
	}
	else if (t->value < data) //������ ������ �� Ŭ ��� > right��
	{
		t->right = AddNode(t->right, data);
	}
	return t;
}

Tree* GetMaxNode(Tree* t)
{
	if (t != NULL)
	{
		if (t->right != NULL)
		{
			return GetMaxNode(t->right);
		}
	}
	return t;
}

Tree* GetMinNode(Tree* t)
{
	if (t != NULL)
	{
		while (t->left != NULL)
		{
			return GetMinNode(t->left);
		}
	}
	return t;
}

Tree* DeleteNode(Tree* t, int target)
{
	Tree* temp;
	if (t->value == target)
	{
		if (t->left == NULL && t->right == NULL) //case1. �ڽ��� �Ѵپ���
		{
			free(t);
			return NULL;
		}
		else if (t->left == NULL) //case2. ������ �ڽ� ��常 �ִ°�� 
		{
			temp = t->right;
			free(t);
			return temp; //������ �ڽ� �뵵�� �� ����
		}
		else if (t->right == NULL)//case3. ���� �ڽ� ��常 �ִ°��
		{
			temp = t->left;
			free(t);
			return temp;
		}
		else //case 4. �Ѵ� �ִ°��
		{
			temp = GetMaxNode(t->left); //���� �ڽ� ��� �� �ִ밪�� ã��
			t->value = temp->value; //���� �ڽ� �� �ִ��� ���� ���� ����
			t->left = DeleteNode(t->left, temp->value); //�ٽ� �����Ϸ� ���
		}
	}
	else if (target < t->value)
	{
		t->left = DeleteNode(t->left, target);
	}
	else //if (target > t->value)
	{
		t->right = DeleteNode(t->right, target);
	}
	return t;
}
//���� ���� ����
//Preorder 
//Inorder
//Postorder

void PrintNode(Tree* t)
{
	if (t != NULL)
	{
		printf("%d ", t->value);
		PrintNode(t->left);
		PrintNode(t->right);
	}
}
