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
	Point operator*(int times)		// 곱셈 연산자 오버로딩, Point 객체와 정수간의 곱셈 가능
	{
		Point pos(xpos * times, ypos * times);		// 곱한 수만큼 증가된 Point 객체를 생성하여 return해줌.
		return pos;
	}
};

int main(void)
{
	Point pos(1, 2);	// 객체 생성
	Point cpy;				

	cpy = pos * 3;		// : cpy = pos.operator*(3)와 동일함자료형이 다른 객체와 int를 곱함. 연산자 오버로딩이 아니라면 할 수 없음.
	cpy.ShowPosition();

	cpy = pos * 3 * 2;  // pos 객체에 3을 곱한 값에 다시 2를 곱하는 연산, 그 연산 결과값이 cpy객체에 저장됨.
	cpy.ShowPosition();
	return 0;
}