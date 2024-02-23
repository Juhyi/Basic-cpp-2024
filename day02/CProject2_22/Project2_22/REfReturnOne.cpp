#include <iostream>
using namespace std;

int& RefRetFuncOne(int& ref) //매개변수가 참조변수, num1이 증가
{
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int &num2 = RefRetFuncOne(num1);	//return된 값을 num2에 저장 num1 =2

	num1++;	// num1 = 3
	num2++; // num2 = 4 , num1 =4
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
	return 0;
}
// 변수 1개 , 접근 가능한게 3개일뿐