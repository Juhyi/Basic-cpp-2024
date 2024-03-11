#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)		// 생성자 선언과 초기화 => 입력이 없으면 초기화 값을 사용함.
	{  }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++()			// ++은 단항 연산자, 연산자 오버로딩 멤버함수로 정의
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point& ref);	// -- 은 단항 연산자, operator-- friend로 선언 xpos, ypos 함수 밖에서 사용가능
};

Point& operator--(Point& ref)	// 연산자 오버로딩 전역변수로 정의, -- & 참조연산자로 ref 주소값을 입력  받음.
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main(void)
{
	Point pos(1, 2);
	++pos;			    // 전위 연산자, 연산을 수행하기 전에 1 증가시켜줌 ++은 멤버함수로 정의된 연산자 오버로딩 : pos.operator++()의 의미
	pos.ShowPosition();   
	--pos;				// --는 전역변수로 정의된 연산자 오버로딩 : operator--(pos)의 의미
	pos.ShowPosition();

	++(++pos);		   		
	pos.ShowPosition();
	--(--pos);			
	pos.ShowPosition();
	return 0;
}