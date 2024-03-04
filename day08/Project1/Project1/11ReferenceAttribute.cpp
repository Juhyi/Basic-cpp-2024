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

/*void GoodFunction(const First& ref) {}
* => 인자가 First 객체 또는 First를 직접 혹은 간접적으로 상속하는 클래스의 객체
* => 인자로 전달되는 객체의 실제 자료형에 상관없이 함수 내에서 Fisrt클래스에서 정의된 함수만 호출할 수 있음.
*/