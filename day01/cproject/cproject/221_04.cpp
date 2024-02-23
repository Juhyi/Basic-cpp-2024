/*
* 반복 제어문 : for
*/
#include <iostream>
using namespace std;

// int sum; 전역변수 사용은 지양하는게 좋음
int main() {
	
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		
		sum += i;	// sum = sum + 1
	}
	cout << sum << endl;

		return 0;
}