#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n) : num(n) {  }
	void ShowData() { cout << num << endl; }

	Number* operator->()		// -> 연산자 오버로딩 : 객체의 주소 값의 반환
	{
		return this;		// 객체 자기 자신을 반환함
	}

	Number& operator*()			// * 연산자 오버로딩 : 객체를 참조형태로 반환하도록 Number&
	{
		return *this;		// 객체 자신을 참조 형태로 반환
	}
};

int main(void)
{
	Number num(20);			// 객체 생성
	num.ShowData();			
		
	(*num) = 30;			// (num.operator()) =30과 동일, *연산자 오버로딩의 결과 => (*num) : 객체 num이 포인터 변수처럼 사용
	num->ShowData();	    // ->연산자 오버로딩의 결과 => 객체 num이 포인터 변수처럼 사용
	(*num).ShowData(); 

	return 0;
}
// ->, * 연산자 오버로딩 => 스마트 연산자 공부하기  08번 파일에서 계속