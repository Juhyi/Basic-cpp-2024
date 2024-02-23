// 매크로함수 => 일반적인 함수에 비해  실행속도의 이점이 있다. 많이 사용안함

#include <iostream>
using namespace std;

// #define SQUARE(X) ((X) * (X)) => 매크로 함수,(밑의 함수와 동일한 작동, 형식이 간단) 간단한 식이나 함수일 경우 사용, 대문자로 작성하기 
// 매크로를 사용하면 타입의 제약을 받지 않음. 5.5를 입력받아도 실행가능, inline 함수로 구현하면 이 장점이 사라진다.
// # 매크로가 2개 사용, 매크로는 전처리기에서 처리함.

inline int SQUARE(int x)
{
	return x * x;
}

int main(void)
{
	cout << SQUARE(5) << endl;
	cout << SQUARE(12) << endl;
	return 0;
}
