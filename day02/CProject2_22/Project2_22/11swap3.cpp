/*
* 참조자를 사용하여 swap
*/


#include <iostream>
using namespace std;

int swap(int& a, int& b)
{
	int temp; // temp 변수 선언
	temp = a; // a, b 값 교환 과정
	a = b;    
	b = temp; 
}

int main() {

	int a = 10;		
	int b = 20;

	cout << "before:  " << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	swap(a, b);		

	cout << "after:  " << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	return 0;
}