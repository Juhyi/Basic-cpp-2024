#include <iostream>
using namespace std;
/*
* swap01 �Լ��� ����
*/

void swap(int *num1, int *num2) {	//  �ּҸ� ���� �� �ִ� ������ ������ ����
	
	
	int temp;
	temp = *num1;	// �ּ��� �����͸� ����
		
	*num1 = temp;
	*num2 = *num1;

	// ���� ������� *�� �ƹ� �ǹ� ������, ǥ�������� ������ &�� ����� ���� ��� ���������� �𸥴�.
	
	

}



int main() {

	int a = 10;		// ��������
	int b = 20;

	cout << "befor:  " << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	swap(&a, &b);		// ������ �ּҸ� ����

	cout << "after:  " << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	return 0;
}