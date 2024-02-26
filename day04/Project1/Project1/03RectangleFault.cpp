#include <iostream>
using namespace std;

class Point
{
public:			// 맴버변수를 public
	int x;		// x좌표의 범위는 0 이상 100이하
	int y;		// y좌표의 범위는 0 이상 100이하
};

class Rectangle
{
public:
	Point upLeft;		// 멤버 변수의 타입이  Point타입. 
	Point lowRight;

public:
	void ShowRecInfo()
	{
		cout << "좌 상단: " << '[' << upLeft.x << ", ";
		cout << upLeft.y << ']' << endl;
		cout << "우 하단: " << '[' << lowRight.x << ", ";
		cout << lowRight.y << ']' << endl << endl;

	}
};

int main(void)
{
	Point pos1 = { -2, 4 };		// Point 타입의 객체 
	Point pos2 = { 5, 9 };
	Rectangle rec = { pos2, pos1 };	// 객체를 전달하면서 rec 객체 생성 및 초기화
	rec.ShowRecInfo();
	return 0;

}