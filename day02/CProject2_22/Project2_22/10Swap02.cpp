#include <iostream>
using namespace std;
/*
* swap01 함수로 구현
*/

void swap(int *num1, int *num2) {	//  주소를 받을 수 있는 포인터 변수를 선언
	
	
	int temp;
	temp = *num1;	// 주소의 데이터를 참조
		
	*num1 = temp;
	*num2 = *num1;

	// 변수 선언상의 *는 아무 의미 없지만, 표기해주지 않으면 &를 사용할 때에 어디서 참조받을지 모른다.
	
	

}



int main() {

	int a = 10;		// 지역변수
	int b = 20;

	cout << "befor:  " << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	swap(&a, &b);		// 변수의 주소를 전달

	cout << "after:  " << endl;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	return 0;
}