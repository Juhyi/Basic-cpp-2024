#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)		// 생성자 
	{
		cout << "Point 객체 생성" << endl;
	}
	~Point()											// 소멸자
	{
		cout << "Point 객체 소멸" << endl;
	}
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	friend ostream& operator<<(ostream& os, const Point& pos);   // friend로 선언, 전여함수로 정의
};
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

// 스마트 포인터는 사실 객체, 포인터 역할을 하는 객체를 말함
class SmartPtr
{
private:
	Point* posptr;	// 멤버변수를 Point타입의 포인터 멤버 변수를 선언
public:
	SmartPtr(Point* ptr) : posptr(ptr)	// 생성자의 인자로 전달되는 주소값은 new연산에 의해 동적 할당된 객체의 주소값이라는 가정
	{  }

	Point& operator*() const	// (스마트 포인터) : 포인터처럼 동착하는 객체:  39, 43 행의 함수 정의는 필수임. 
	{							// => 소멸자를 호출하지 않아도 자동으로 delete 연산이 실행됨.
		return *posptr;
	}
	Point* operator->() const
	{
		return posptr;			// 포인터로 반환
	}
	~SmartPtr()
	{
		cout << "SmartPtr 객체 소멸" << endl;
		delete posptr;
	}
};

int main(void)
{
	SmartPtr sptr1(new Point(1, 2));		//  new로 객체를 생성하는 동시에 스마트포인터 SmartPtr 객체가 가리키게하고 있음
	SmartPtr sptr2(new Point(2, 3));		// => sptr1,2,3은 Point 객체를 가리키는 포인터처럼 동작
	SmartPtr sptr3(new Point(4, 5));		
	cout << *sptr1;			// sptr1,2,3은 포인터 처럼 *연산을 실행		
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);		// sptr1,2,3은 포인터처럼 ->연산을 실행.
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;
	return 0;
}

// 생성과 소멸은 역순, Smartptr 소멸 -> Point 소멸