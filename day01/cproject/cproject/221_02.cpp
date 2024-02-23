#include <iostream>
using namespace std;

int main()
{
	int inKey;
	cout << "정수입력 > ";
	cin >> inKey;

	if (inKey == 3) {	// if(조건식){ ... 실행문}  실행문이 한줄일 경우 {} 생략 가능
		cout << "빙고" << endl;
	}
	else if (inKey > 3) {
		cout << "숫자가 큽니다." << endl;
	}
	else if (inKey < 3) {
		cout << "숫자가 작습니다." << endl;
	}
	else cout << "잘못 입력하셨습니다." << endl;
	return 0;
}
/*
* if ~ else 문
*/