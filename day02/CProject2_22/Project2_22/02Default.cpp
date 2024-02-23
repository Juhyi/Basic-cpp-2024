#include <iostream>
using namespace std;

int Adder(int num1 = 1, int num = 2);	// 함수 선언, 함수 정의를 호출 밑에서 정의한다면 위에서 함수 선언을 먼저 해줘야 한다. 

char func(); // 함수 선언

char func() {
	cout << "Hi" << endl;
	return 0;
}


int main(void)
{
	cout << Adder() << endl;	// 함수 호출: Adder()
	cout << Adder(5) << endl;	// 왼쪽부터 매개변수 적용되고 나머지는 default 값이 입력되어짐.
	cout << Adder(3,5) << endl;
	cout << func() << endl;
	return 0;

}

int Adder(int num1, int num2)	// 함수 정의
{
	return num1 + num2;
}

// 클래스 안에 들어가는 함수를 메서드라고 부름 **** <중요>
