#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt;	// static 멤버변수, 클래스 변수: 객체를 생성하던지 말던지 메모리 공간에 딱 하나만 할이 되어 공유되는 변수
public:						// static 멤버변수는 객체 내에 존재하는 것이 아님. But 멤버변수처럼 접근할 수 있는 권한을 가짐.
	SoSimple()				// static **객체가 없어도 됨.  static 멤버함수 내에서는 static 멤버변수와 static 멤버함수만 호출이 가능하다.
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt = 0;		// static 멤버변수의 초기화, 이미 메모리 공간에 할당된 변수이므로 외부에서 초기화가 이루어짐.
			
class SoComplex
{
private:
	static int cmxObjCnt;		// 외부의 접근 제한하여 다른 영역에서 잘못 접근하는 일이 발생하지 않음.
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 &SoComplex 객체" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();		// 임시객체  생성, 이름없는 객체 생성됨. 
	return 0;
}