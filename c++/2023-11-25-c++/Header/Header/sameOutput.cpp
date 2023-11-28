/*#include <iostream>
#include <string>

class MyClass {
public:
    int value;
    std::string text;

    MyClass(int v, const std::string& t) : value(v), text(t) {}
};

int main() {
    MyClass obj1(1, "Test");     // �Լ� ȣ��� ������ �ʱ�ȭ
    MyClass obj2{ 1, "Test" };     // uniform initialization
    MyClass obj3 = { 1, "Test" };  // uniform initialization (���� ����)

    std::cout << obj1.value << " " << obj1.text << std::endl;
    std::cout << obj2.value << " " << obj2.text << std::endl;
    std::cout << obj3.value << " " << obj3.text << std::endl;

    return 0;
}*/

/*
* 
* 
�� �� ���� ǥ�� ����� ��� ��ü�� �ʱ�ȭ�ϴ� ����� ��Ÿ����,
C++������ �̵��� ��Ʋ� 
"�ʱ�ȭ ����Ʈ" �Ǵ� "�ʱ�ȭ ���"�̶�� �մϴ�.
�׷��� ������ ���Ǵ� ���ƿ� ���� �ణ�� ���̰� �ֽ��ϴ�.



MyClass (1, "Test"):
�̰��� �Լ� ȣ��� ������ �������� ���Դϴ�.
���� �����ڰ� �� ���� �Ű������� �޴´ٸ�, 
�̴� ������ ȣ��� �ؼ��� ���Դϴ�.
�׷��� C++���� �̴� ���� ������ ���� �� �ϳ���
���� Ŭ������ ������ �ʱ�ȭ�� ���� ������� ���˴ϴ�.


MyClass {1, "Test"}:
�̰��� C++11 ���� ���Ե� "uniform initialization" �����Դϴ�.
�߰�ȣ�� ����Ͽ� �ʱ�ȭ�ϸ�,
�̴� �ʱ�ȭ ����Ʈ(initializer list)�� ���ֵ˴ϴ�. 
�� ����� �ʱ�ȭ ��Ģ�� �� ��Ȯ�ϰ� �ϰ�,
�� �ϰ��� �ʱ�ȭ ������ �����մϴ�.



MyClass = {1, "Test"};:
�̰��� �̹� ������ ��ü�� �ʱ�ȭ ����Ʈ�� ����Ͽ� 
�ٽ� �ʱ�ȭ�ϴ� ����Դϴ�. 
�̴� C++11 ���Ŀ� ���Ե� �ʱ�ȭ ����Ʈ�� �Ϻ��Դϴ�



.*/