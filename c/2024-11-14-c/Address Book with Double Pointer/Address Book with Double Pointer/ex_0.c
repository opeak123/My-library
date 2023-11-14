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


void AddBook(AddressBook** book, const char* name, int day, int number)
{
	// ���ο� �ּҷ� �׸��� �������� �Ҵ�
	AddressBook* newBook = (AddressBook*)malloc(sizeof(AddressBook));

	// �̸�, �������, ��ȣ ����
	//newBook->name = strdup(name);  // �̸��� ���� ���� �Ҵ� �� ����
	newBook->name = _strdup(name);
	newBook->birthday = day;
	newBook->number = number;

	// �� �׸��� �ּҷ��� �� �տ� �߰�
	newBook->bookPointer = *book;
	*book = newBook;
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

    return 0;
}
