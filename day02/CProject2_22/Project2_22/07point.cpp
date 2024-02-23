#include<iostream>
using namespace std;

int main() {

	const int num = 10;

	int num1 = 10;
	int *pnum1;			// <포인터변수 선언> - 포인터(주소)변수 pnum1 선언, int 타입의 주소값을 저장할 수 있는 변수를 선언.  * : 포인터 변수라는 기호 (의미X)
	pnum1 = &num1;		// 변수 num1의 주소를 포이터변수 pnum1에 저장한다. & : 주소 연산자

	cout << "num에 저장된 값" << num << endl;
	cout << "num1에 저장된 값" << num1 << endl;
	cout << "num1의 주소값" << &num1 << endl;
	cout << "pnum1에 저장된 값" << pnum1 << endl; 
	cout << "pnum1에 저장된 것의 데이터: " << *pnum1 << endl; // 주소에 해당하는 곳의 값이 출력됨. 코드 부분의  * : 가리키는 곳의 데이터


	return 0;
}

/*
* C에서 메모리
* 1. 스택 : 지역변수, 매개변수 <범위가 있을때 사용>
* 2. heap : 사용자에게 할당된 영역
*		- 사용을 하려면 malloc()으로 할당을 받는다 - free()로 반환 - 반환이 되지 않으면 메모리가 낭비됨. 
* 3. data : 함수, 전역변수, 상수, 문자리터럴 < 프로그램이 시작되면 저장하는 것들>
*/

// 레퍼런스 => 포인터