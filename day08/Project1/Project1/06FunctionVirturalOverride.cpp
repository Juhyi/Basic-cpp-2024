#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc()    // Myfunc() 함수 virtural로 선언, 이후 코드의 Myfunc() 함수는 virtual을 붙이지 않아도 자동으로 가상함수가 됨
	{																					// 하지만 붙이는게 좋음	
		cout << "FirstFunc" << endl;
	}
};

class Second : public First
{
public:
	virtual void MyFunc()			
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second
{
public:
	virtual void MyFunc()
	{
		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	Third* tptr = new Third();			// Third 타입의 tptr 포인터 변수로 참조, Third 객체 생성 
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();				// 함수가 가상함수로 선언되었으므로 해당함수 호출시, 포인터의 자료형을 기반이 아닌
	sptr->MyFunc();				// 포인터 변수가 실제로 가리키는 객체를 참조하여 호출의 대상을 결정한다. 
	tptr->MyFunc();				
	delete tptr;
	return 0;
}
