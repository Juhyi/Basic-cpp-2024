#include <iostream>

using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int ax = 0, int ay = 0) : x(ax), y(ay)
	{  }
	void viewPoint() 
	{
		cout << '[' << x << ", " << y << ']' << endl;
	}

	Point operator+(const Point& ref)
	{
		return Point(x + ref.x, y + ref.y);
	}

	friend Point operator+(int val, const Point& ref); // friend 선언

	friend ostream& operator<<(ostream& os, const Point& p);	// main의 cout << 객체를 출력하기 위한 ostream를 정의하기 위한 함수

}; 

ostream& operator<<(ostream& os, const Point& p)		// cout객체의 참조값을 반환하는 형태로 정의
{
	os << '[' << p.x << ", " << p.y << ']';
	return os;
}

Point operator+(int val, const Point& ref)
{
	return Point(val + ref.x, ref.y);
}



int main()
{
	Point a(10, 20);
	Point b(30, 40);
	Point c = a + b;
	Point d = a + 100;
	Point e = 100 + a;

	d.viewPoint();
	c.viewPoint();

	cout << c << endl;
	cout << d << endl;
	cout << e << endl;


	return 0;
}