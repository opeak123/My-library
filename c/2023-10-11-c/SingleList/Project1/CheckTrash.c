//#include <stdio.h>
//#include <limits.h> //CHAR_BIT == 1 byte 
//
//int main() {
//    int myValue; 
//
//    // myValue�� � ���� ����ִ��� Ȯ��
//
//    int* ptr = &myValue;
//    for (int i = 0; i < sizeof(myValue) / sizeof(char); i++) 
//    {
//        printf("Byte %d: %02X\n", i, *((char*)ptr + i));
//    }
//
//    return 0;
//}