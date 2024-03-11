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
	Point operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point operator*(int times, Point& ref);	//friend로 선언
};

Point operator*(int times, Point& ref)		// Point 타입의 operation 함수 정의 : 교환법칙의 성립을 목적으로 함수를 추가로 정의
{											// 매개변수를 int 타입과 Potin 타입의 참조연산자로 주소값을 입력 받음. 
	return ref * times; 					// return 값으로 연산순서 교환함. return ref.operator*(time)와 동일. 
}

int main(void)
{
	Point pos(1, 2);
	Point cpy;
	cpy = 3 * pos;			// 교환법칙이 성립됨. cpy = operator*(3, pos)와 동일함.  
	

	cpy.ShowPosition();

	cpy = 2 * pos * 3;
	cpy.ShowPosition();
	return 0;
}