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
	return result;  // 출력이 있으면 return문 필요.
}

int divid(int a, int b) {
	int result = 0;
	
	if (a == 0 || b == 0) {
		cout << "0을 포함한 나눗셈은 실행할 수 없습니다.";
		return 0;
	}
	
	result = a / b;
	return result;
}

int main() {
	int num1, num2 = 0;
	char name;
	cout << "첫번째 숫자를 입력: ";
	cin >> num1; 

	cout << "연산자를 입력 (+, -, *, /): ";
	cin >> name; 

	cout << "두번째 숫자를 입력: ";
	cin >> num2;





	switch (name) {
	case '+':
		cout << "결과: " << add(num1, num2) << endl;
		break;
	case '-':
		cout << "결과: " << minu(num1, num2) << endl;
		break;
	case '*':
		cout << "결과: " << mulit(num1, num2) << endl;
		break;
	case '/':
		cout << "결과: " << divid(num1, num2) << endl;
		break;
	default:
		cout << "잘못된 연산자입니다." << endl;
	}


	return 0;

}