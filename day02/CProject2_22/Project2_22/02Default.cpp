#include <iostream>
using namespace std;

int Adder(int num1 = 1, int num = 2);	// �Լ� ����, �Լ� ���Ǹ� ȣ�� �ؿ��� �����Ѵٸ� ������ �Լ� ������ ���� ����� �Ѵ�. 

char func(); // �Լ� ����

char func() {
	cout << "Hi" << endl;
	return 0;
}


int main(void)
{
	cout << Adder() << endl;	// �Լ� ȣ��: Adder()
	cout << Adder(5) << endl;	// ���ʺ��� �Ű����� ����ǰ� �������� default ���� �ԷµǾ���.
	cout << Adder(3,5) << endl;
	cout << func() << endl;
	return 0;

}

int Adder(int num1, int num2)	// �Լ� ����
{
	return num1 + num2;
}

// Ŭ���� �ȿ� ���� �Լ��� �޼����� �θ� **** <�߿�>
