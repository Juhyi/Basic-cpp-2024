#include<iostream>
using namespace std;

int global = 100; //전역변수- 프로그램전체에서 사용가능
int global1 = 200;

int main()
{
	int val = 100;  // 지역변수 - 선언된 범위에서만 사용가능
	global = 200;	// 전역변수이므로 main 함수 안에서 사용할 수 있음 

	int global1 = 300;	//전역변수로 선언한 global1을 지역으로 이름을 동일하게 선언 => 전역변수로 선언한게 가려짐. 우선순위 : 지역변수 >> 전역변수



	cout << "전역변수 global: " << global << endl;
	cout << "지역변수: " << val << endl;
	
	cout << "전역변수 global1: " << global1 << endl;

	return 0;
}

void func()
{	
	int val = 0;  // func에서 val을 지역 변수로 선언하였으므로 func()에서 사용가능.
	global = 10;
	global1 = 10;
	val = 10;  // val은 main 함수 범위에서만 사용가능함, main 함수를 벗어나면 사용할 수 없음.
}