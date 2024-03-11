/*
* vector 객체를 생성하고 정수를 입력 받을때 마다 벡터에 삽입하고 평균을 출력하시오.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;	// int 타입의 vector 생성
	int sum = 0;

	
	while (true) {
		int inKey;
		
		cout << "숫자를 입력하세요 : " << endl;
		cin >> inKey;

		v.push_back(inKey);		// 입력을 받을때마다 벡터에 삽입
		for (int i = 0; i < v.size(); i++) {
			cout << v.at(i) << endl;
		}
		sum += inKey;
		float average = sum / v.size();		// 평균
		cout << "평균: " << average << endl;

		if (!inKey) {
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
	}
	
	return 0;
}


