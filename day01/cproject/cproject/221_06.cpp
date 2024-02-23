// overriding : 상속일때 사용, 재정의
// overloading : 다중 정의, 함수의 이름이 동일할때 매개변수의 갯수, 타입이 다르면 오버로딩이 허용됨. 

#include <iostream>
using namespace std;

void MyFunc(void) 
{
	cout << "MyFunc(void) called" << endl;
}

void MyFunc(char)
{
	cout << "MyFunc(char c) called" << endl;
}

void MyFunc(int a, int b)
{
	cout << "MyFunc(int a, int b) called" << endl;
}

int main() {
	MyFunc();
	MyFunc('A');
	MyFunc(12, 13);
	return 0;  //출력이 있으면 return문 필요.

}