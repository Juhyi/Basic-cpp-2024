#include <iostream>
using namespace std;

int Adder(int num1 = 1, unt num2 = 2)
{
	return num1 + num2;
}

int main(void)
{
	cout << Adder() << endl;
	cout << Adder(5) << endl;   // 입력을 2개 받는 함수에 실인수를 하나만 입력할 경우 => 
	cout << Adder(3, 5) << endl;
	return 0;
}