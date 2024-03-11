#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)		// 생성자
	{  }
	Point operator+(const Point& pos) const		// +연사자 오버로딩
	{
		return Point(xpos + pos.xpos, ypos + pos.ypos);	        // 임시 객체를 생성과 동시에 반환 => return 문에서도 가능.
	}
	friend ostream& operator<<(ostream& os, const Point& pos);	// friend 선언-> 전역변수에서 정의
};

ostream& operator<<(ostream& os, const Point& pos)	 // << 연산자 오버로딩 
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}	

class Adder		// => 함수처럼 동작하는 클래스 : 펑터(Functor) or 함수 오브젝트(Function Object)
{
public:
	int operator()(const int& n1, const int& n2)		// 정수 2개의 값을 받아 더한 후 반환하는  () 연산자 오버로딩
	{
		return n1 + n2;
	}
	double operator()(const double& e1, const double& e2)	// 실수 2개의 값을 받아 더한 후 반환하는 () 연산자 오버로딩
	{
		return e1 + e2;
	}
	Point operator()(const Point& pos1, const Point& pos2)	// 객체 2개를 더한 후 반환하는 ()연산자 오버로딩
	{
		return pos1 + pos2;		// 객체를 더하므로 연산자 오버로딩 필요. 
	}
};

int main(void)
{
	Adder adder;
	cout << adder(1, 3) << endl;				// adder라는 이름의 함수를 호출하여 값을 출력, adder는 객체이지만 함수처럼 동작
	cout << adder(1.5, 3.7) << endl;			// 44행과 동일
	cout << adder(Point(3, 4), Point(7, 9));	// Point형 임시객체 2개를 생성하여 함수의 인자로 전달 => 함수의 호출문에서도 임시객체 생성 가능
	return 0;
}