/*
* �ݺ� ��� : for
*/
#include <iostream>
using namespace std;

// int sum; �������� ����� �����ϴ°� ����
int main() {
	
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		
		sum += i;	// sum = sum + 1
	}
	cout << sum << endl;

		return 0;
}