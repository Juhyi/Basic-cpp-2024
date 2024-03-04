#include <iostream>
using namespace std;

class First
{
public:
	void MyFunc()
	{
		cout << "FirstFunc" << endl;
	}
};

class Second : public First    // First의 상속된 Second 
{
public:
	void MyFunc()				// 자기의 메서드는 1개이지만 상속을 받아 총 2개의 메서드
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second
{
public:
	void MyFunc()				// 자기의 메서드는 1개이지만 상속을 받아 총3개의 메서드 사용 가능
	{
		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	Third* tptr = new Third();		// Third 타입의 tptr 포인터 변수로 참조, Third 객체 생성
	Second* sptr = tptr;			// Second 타입의 sptr 포인터 변수로 참조
	First* fptr = sptr;				// First 타입의 fptr 포인터 변수로 참조


	// 객체포인터 타입을 기준으로 접근 범위가 결정됨.
	// 오버라이딩된 경우는 부모것은 자식것으로 가려짐.
	fptr->MyFunc();  // First 클래스의 메서드
	sptr->MyFunc();  // Second 클래스의 메서드, 부모것이 가려지기 때문에 
	tptr->MyFunc();  // Third 클래스의 메서드, 부모것이 가려지기 때문에


	sptr->First::MyFunc();  // 부모 클래스의 메서드에 접근 하고 싶으면 First:: 로 표현해주어서 접근한다. 
	
	delete tptr;
	return 0;
}
 // 객체지향이어야하는데 포인터 타입을 기준으로 접근 범위가 결정되므로 가상함수(객체지향의 개념)라는 것을 사용함. 