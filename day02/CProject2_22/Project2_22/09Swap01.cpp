#include <iostream>
using namespace std;


int main(){

	int a = 10;
	int b = 20;
	
	cout << "바꾸기 전" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	int temp;  // 바꾸기 전의 a값을 저장할 변수 temp 선언
	
	temp = a; // temp에 a값 대입
	a = b;
	b = temp;

	
	cout << "바꾼 후" << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;


	return 0;
}