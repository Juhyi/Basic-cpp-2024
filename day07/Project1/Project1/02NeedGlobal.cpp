#include <iostream>
using namespace std;

int simObjCnt = 0;		// 전역변수 => 전역은 데이터 오염이 생길 확률이 높음, 사용을 지양하는 것이 좋음
int cmxObjCnt = 0;		// 전역변수 

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 1SoComplex 객체" << endl;
	}
};

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;	
	SoComplex();		// 임시객체  생성, 이름없는 객체 생성됨. 
	return 0;
}