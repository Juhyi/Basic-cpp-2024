#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point operator+(const Point& pos1, const Point& pos2);	// friend로 선언 : 연산자 오버로딩에서 사용 (무분별하게 사용시 캡슐화를 위배함)
};

Point operator+(const Point& pos1, const Point& pos2)			// 전역함수로 선언한 연산자 오버로딩
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);  // 연산자 오버로딩 몸체부분의 객체 생성 자체가 pos1 + pos2를 가리킴
	return pos;												  // friend이기 때문에 xpos 사용 가능. friend로 선언하지 않았다면 getter를 사용하여 xpos 사용가능.
}

int main(void)
{
	Point pos1(3, 4);		   // 객체 생성
	Point pos2(10, 20);		   // 객체 생성
	Point pos3 = pos1 + pos2;  // 연산자 오버로딩이 전역함수로 정의되어있으므로 객체를 통해 함수를 접근할 필요없이 객체의 연산이 가능하다.
							   // pos1.operator+(pos2); => 멤버함수 일때 연산자 오버로딩 호출 형식
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}
