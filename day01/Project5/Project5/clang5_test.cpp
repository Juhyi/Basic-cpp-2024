#include <iostream>
using namespace std;

int main(void)
{
	int a = 10;
	int b = 20;
	int c = 30; 
	int ary[3] = { 10, 20, 30 }; // 배열선언 => 정수형 방을 연속으로 3개 만듬/ a, b, c를 선언하고 각각 10, 20, 30으로 초기화. 
	ary[0] = 1111; //배열 ary의 첫 번째 요소(배열의 0번 방에)를 1111로 변경.
	ary[1] = 100;
 
	for (int i = 0; i < 10; i++) {
		cout << i << endl;
		// for 루프: i가 0에서 9까지 증가하면서 루프를 실행.
			//cout << i << endl; : 현재의 i 값을 출력하고 새 줄로 이동.
	}
	return 0;
}

// 그 후 for 루프가 실행되며 0부터 9까지의 숫자를 출력
// -> 마지막으로 0을 반환하여 프로그램을 종료

/*
* 자료형
*  문자: 문자(char)/문자열
*  숫자: 정수(int)/실수
*/