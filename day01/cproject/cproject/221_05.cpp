/*
* 반복 제어문 : while
*/

#include <iostream>
using namespace std;

int main() {
	int i = 1;
	int sum = 0;
	while (i <= 100) {
		sum += i;
		i++;
		if (i == 11) break;

	}
	cout << sum << endl;

	return 0;

}
