#include <iostream>
using namespace std;

int main(void)
{
	int num = 10;		//지역변수 선언 및 초기화
	cout << "num: " << num << endl;

	int *pnum = &num;	// 주소로 num변수에 접근, 주소에 해당하는 곳의 값이 출력됨
	int &rnum = num;	// 참조로 num변수에 접근

	// int& ref; (X) => 선언과 동시에 참조할 변수를 초기화(NULL로 초기화 X) 해주어야함 상수도 동일
 
	num = 20;
	cout << endl;
	cout << "num: " << num << endl;
	cout << "*pnum: " << *pnum << endl;		
	cout << "rnum: " << rnum << endl;		

	*pnum = 30;
	cout << endl;
	cout << "num: " << num << endl;
	cout << "*pnum: " << *pnum << endl;
	cout << "rnum: " << rnum << endl;

	rnum = 40;
	cout << endl;
	cout << "num: " << num << endl;
	cout << "*pnum: " << *pnum << endl;
	cout << "rnum: " << rnum << endl;



	return 0;
}