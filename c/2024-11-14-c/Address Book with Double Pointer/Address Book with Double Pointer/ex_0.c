//Address Book with double Pointer
//https://m.cafe.daum.net/c-study/4tdN/395

//1.����
//2.�̸� �˻�
//3.��ȣ �˻�
//4.�̸� ����
//5.������� ����
//6.��ȭ��ȣ�� ����
//7.��ȭ��ȣ�� ���
//8.��ȭ��ȣ�� ����
//0. ����

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <stdbool.h>

//#pragma warning(disable:4996)

typedef struct AddressBook** AddressBookPointer;
//�ּҷ� ����ü ����
typedef struct AddressBook
{
	//�̸�
	char* name;
	//�������
	int birthday;
	//��ȣ
	int number;
	//next pointer
	AddressBookPointer bookPointer;
}AddressBook;


//1.����
void AddBook(AddressBook** book, const char* name, int day, int number);
//2.�̸� �˻�
void NameSearch(AddressBook** book, char* name);
//3.��ȣ �˻�
void NumberSearch(AddressBook** book, int number);
//4.�̸� ����
void SortByName(AddressBook** book);
//5.������� ����
void SortByDay(AddressBook** book);
//6.�ּҷ� ���� (��ȣ,�̸�,�������)
void ModifyBook(AddressBook** book);
//7.��ȭ��ȣ�� ���
void PrintBook(void);
//8.��ȭ��ȣ�� ����
void DeleteBook(void);
//0. ����
//���������Ұ��� 

//��� ������� Ȯ��
bool IsEmpty(AddressBook* book)
{
	return book == NULL;
}

void AddBook(AddressBook** book, const char* name, int day, int number)
{
	//���� �Ҵ�
	AddressBook* newBook = (AddressBook*)malloc(sizeof(AddressBook));

	// �̸�, �������, ��ȣ ����
	//malloc + strcpy
	newBook->name = _strdup(name);
	newBook->birthday = day;
	newBook->number = number;

	// �� �׸��� �ּҷ��� �� �տ� �߰�
	newBook->bookPointer = *book;
	*book = newBook;
}

void NameSearch(AddressBook** book, char* name)
{
	if (IsEmpty(book))
		return;
	
	//Double Pointer Address
	AddressBook* temp = *book;
	//��� üũ
	int countNumber = 0;
	while (temp != NULL)
	{
		printf("\nname : [%s]\n",temp->name);
//		putchar('\n');
		printf("birthday : [%d]  number : [%d]\n", temp->birthday, temp->number);

		countNumber++;
		temp = temp->bookPointer;
	}

	if (countNumber == 0)
	{
		printf("not found\n\n");
	}
}

int main(void)
{
    AddressBook* book = NULL;

    char name[100];
    int day, number;
    printf("put name: ");
	scanf_s("%s", name, (unsigned)_countof(name));
	printf("put bithday: ");
    scanf_s("%d", &day);
    printf("put number: ");
    scanf_s("%d", &number);

    AddBook(&book, name, day, number);

	NameSearch(&book, name);

    return 0;
}
