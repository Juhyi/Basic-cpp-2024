#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref)	//ref �������� num1�� ����
{
	ref++;
	return ref;			// ref�� �� �Լ� �������� ��밡��
}

int main(void)
{
	int num1 = 1;
	int num2 = RefRetFuncOne(num1);		// �Ϲ� ������ ���� num2= 2

	num1 += 1;	  // num1 = 3
	num2 += 100;  // num2 = 102
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}
// ���� 2��