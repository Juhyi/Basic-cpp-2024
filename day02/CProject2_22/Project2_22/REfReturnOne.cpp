#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref) //�Ű������� ��������, num1�� ����
{
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int &num2 = RefRetFuncOne(num1);	//return�� ���� num2�� ���� num1 =2

	num1++;	// num1 = 3
	num2++; // num2 = 4 , num1 =4
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}
// ���� 1�� , ���� �����Ѱ� 3���ϻ�