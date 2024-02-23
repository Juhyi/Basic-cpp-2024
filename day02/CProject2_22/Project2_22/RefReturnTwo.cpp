#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref)	//ref 참조변수 num1의 별명
{
	ref++;
	return ref;			// ref는 이 함수 내에서만 사용가능
}

int main(void)
{
	int num1 = 1;
	int num2 = RefRetFuncOne(num1);		// 일반 변수로 받음 num2= 2

	num1 += 1;	  // num1 = 3
	num2 += 100;  // num2 = 102
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}
// 변수 2개