#include <iostream>

int main()
{
	const int num = 10;		// 상수를 선언할때는 선언과 동시에 초기화 필수
	//int& ref = num;			// 상수화 되어있다면 어떤 걸 통해도 값을 변경할 수 없다.

	const int& ref = 30;		// 임시로 생성한 변수를 상수화하여 참조자가 참조하도록 할 수 있음.
								// 상수화된 변수를 참조하는 형태

	return 0;
}

// int a = 10;
// int b = 20;
// int res = a + b;

// 레지스터 -> cpu(연산)만 사용하는 메모리, 실행속도 빠름, 비쌈
// heap 영역에서  malloc()대신에 c++에서 new로 메모리 할당, free()대신에 delet로 반환.