#include <iostream>

void func() {

	// ..
}

int main()
{
	func();
	return 0;
}

const int mum = 1000; // 상수는 선언과 동시에 초기화 필수

ClassName object;
ClassName* p = new ClassName; // new 연산자는 힙영역에 메모리를 할당하고 그 주소를 리턴한다. 객체 생성 힙영역에서 사용은 스택에서 함.
                              // (포인터 변수 사용) 타입 일치 시켜야함. 

char a = 'a';
int* p = &a;