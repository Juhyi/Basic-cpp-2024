#include <iostream>
using namespace std;

int Adder(int num1 = 1, unt num2 = 2)
{
	return num1 + num2;
}

int main(void)
{
	cout << Adder() << endl;
	cout << Adder(5) << endl;   // �Է��� 2�� �޴� �Լ��� ���μ��� �ϳ��� �Է��� ��� => 
	cout << Adder(3, 5) << endl;
	return 0;
}