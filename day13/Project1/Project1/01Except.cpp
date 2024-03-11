#include <iostream>
using namespace std;

void cal(int _n1, int _n2) {
	if (!_n2) throw _n2;
	cout << "더하기: " << _n1 + _n2 << endl;
	cout << "빼기: " << _n1 - _n2 << endl;
	cout << "곱하기: " << _n1 * _n2 << endl;
	cout << "나누기: " << _n1 / _n2 << endl;
}
int main(int argc, char* argv[])
{
	int n1, n2;
	cout << "정수 2개를 입력하세요: " << endl;
	cin >> n1 >> n2;
	try {						// try : 예외를 발견
		cal(n1,n2);				// - 예외발생에 대한 검사의 범위를 지정. 
	}
	catch (int exception) {		// catch : 예외를 잡음
		cout << "0으로 나눌 수 없습니다." << endl;		// 예외처리 코드의 삽입
	}

/* - 메인함수 내 예외처리
	cout << "더하기: " << n1 + n2 << endl;
	cout << "빼기: " << n1 - n2 << endl;
	cout << "곱하기: " << n1 * n2 << endl;
	try {
		if (!n2) throw n2;						// 예외를 던짐
		cout << "나누기: " << n1 / n2 << endl;	// - 예외처리 코드 삽입
	}											// try{}catch{} 사이에 다른 문장이 삽입되면 안됨. 	
	catch (int exception) {
		cout << "0으로 나눌 수 없습니다." << endl;
	}
*/
	return 0;
}
// 배열 : 인덱스로 값 찾기, for문
// 배열 : 검색 <--> 수정
// vector : 자동으로 메모리가 할당, template를 통해 vector 구현
// - v.front() 
// - v.back() => 맨 뒤에서 삽입/삭제 가능, push_back을 하면 맨끝에 값을 넣음, pop_back을 하면 맨끝 값 꺼냄.
// 중간 값도 삽입, 삭제 가능  