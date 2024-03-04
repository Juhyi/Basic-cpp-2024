// date : 2024-03-04
// file : test08_Virtual.cpp
// desc :

#include <iostream>

using namespace std;

class Base {
public:
	Base() {};
	~Base() {};
	virtual void Func1() { cout << "Base::Func1()" << endl; }      // 객체 중심으로 되어서 Derived 것이 출력된다
	virtual void Func2() { cout << "Base::Func2()" << endl; }
	void Func3() { cout << "Base::Func3()" << endl; }
};

class Derived : public Base {
public:
	void Func1() { cout << "Derived::Func1()" << endl; }
	void Func3() { cout << "Derived::Func3()" << endl; }
	void Func4() { cout << "Derived::Func4()" << endl; }

	Derived() = default;
};

int main()
{
	Base b;            // Base 타입의 객체변수
	Derived d;         // Derived 타입의 객체변수
	Base* pb = new Derived();         // Base 타입의 객체 포인터


	pb->Func1();
	pb->Func2();
	pb->Func3();

	cout << endl;
	Derived* pd = &d;      // pd에 Derived d의 주소가 들어가
	pd->Func1();         // Derived 함수출력
	pd->Func2();         // Base 함수출력(Derived에 Func2가 없기 때문)
	pd->Func3();         // Derived 함수출력
	pd->Func4();         // Derived 함수출력

	delete pb;      // 잊지말고 삭제하자

	return 0;
}

/*
* 순수가상함수 : 함수의 몸체가 정의되지 않은 가상함수 virtual int func1() const =0; // 형태
* 추상 클래스 : 순수가상함수를 가진 불완전한 클래스, 객체 생성을 하지 못함. 
* - 언젠가 미래에 필요한 클래스를 미리 만들어둠. 지금당장 객체 생성이 필요하지 않은 상태.
*/