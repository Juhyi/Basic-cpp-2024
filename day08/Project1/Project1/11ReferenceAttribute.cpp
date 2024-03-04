#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc()
	{
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc()				// 가상함수 
	{
		cout << "First's SimpleFunc()" << endl;
	}
};

class Second : public First		//  First 클래스의 상속
{
public:
	void SecondFunc()
	{
		cout << "SecondFunc()" << endl;
	}
	virtual void SimpleFunc()			// 가상함수
	{
		cout << "Second's SimpleFunc()" << endl;
	}
};

class Third : public Second
{
public:
	void ThirdFunc()
	{
		cout << "ThirdFunc()" << endl;
	}
	virtual void SimpleFunc()			// 가상함수
	{
		cout << "Third's SimpleFunc()" << endl;
	}
};

int main(void)
{
	Third obj;				// Third 타입의 obj 객체변수, 가상테이블
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	cout << endl;
	Second& sref = obj;		// obj는 Second를 상속하는 Third 객체 => Second형 참조자로 참조 가능.
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();     // Third 클래스에 정의된 SimpleFunc 가상함수 호출됨
	
	cout << endl;
	First& fref = obj;		
	fref.FirstFunc();
	fref.SimpleFunc();		// Third 클래스에 정의된 SimpleFunc 가상함수 호출됨
	return 0;	
}