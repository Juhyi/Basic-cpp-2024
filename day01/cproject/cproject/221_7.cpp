#include <iostream>
using namespace std;

int add(int a, int b) {
	int result = 0;
	result = a + b;
	return result;
}

int minu(int a, int b) {
	int result = 0;
	result = a - b;
	return result;
}

int mulit(int a, int b) {
	int result = 0;
	result = a * b;
	return result;  // ����� ������ return�� �ʿ�.
}

int divid(int a, int b) {
	int result = 0;
	
	if (a == 0 || b == 0) {
		cout << "0�� ������ �������� ������ �� �����ϴ�.";
		return 0;
	}
	
	result = a / b;
	return result;
}

int main() {
	int num1, num2 = 0;
	char name;
	cout << "ù��° ���ڸ� �Է�: ";
	cin >> num1; 

	cout << "�����ڸ� �Է� (+, -, *, /): ";
	cin >> name; 

	cout << "�ι�° ���ڸ� �Է�: ";
	cin >> num2;





	switch (name) {
	case '+':
		cout << "���: " << add(num1, num2) << endl;
		break;
	case '-':
		cout << "���: " << minu(num1, num2) << endl;
		break;
	case '*':
		cout << "���: " << mulit(num1, num2) << endl;
		break;
	case '/':
		cout << "���: " << divid(num1, num2) << endl;
		break;
	default:
		cout << "�߸��� �������Դϴ�." << endl;
	}


	return 0;

}