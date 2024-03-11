/*
* 객체를 더하는 add 멤버함수
*/

#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int ax = 0, int ay = 0) :x(ax), y(ay) {
		cout << "Operator" << endl;
	}
	Point operator+(const Point& other) {		// 함수명을 add로 해도 실행은 되지만 명시적으로 operator+를 사용함으로써 알아보기 쉬움. 
		return Point(x + other.x, y + other.y);
	}
	void showPoint() {
		cout << '[' << x << ", " << y << ']' << endl;
	}
};


int main()
{	
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);
	pos3.showPoint();
	return 0;
}
