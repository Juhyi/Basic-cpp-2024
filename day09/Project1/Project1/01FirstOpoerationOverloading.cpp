/*연산자 오버로딩
- 오버로딩은 함수에서 일어나므로 연산자 오버로딩은 연산자를 함수화하겠다는 것. 
- 함수는 이름을 가져야함 => operateor+를 붙여서 연산자를 함수화해준다. 
*/

#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)	// 생성자 선언과 초기화 => 입력이 없을때 초기화 값을 사용하겠다.
	{  }
	void ShowPosition() const	// 속성 값이 바뀌면 안되므로 상수화 const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator+(const Point& ref)    //operator+라는 이름의 함수 <함수의 정의>멤버함수 형태 출력: Point, operator+ : 함수이름 (안에 내용): 입력 
	{									 // 동일한 타입의 입력을 31행에서 받음
		Point pos(xpos + ref.xpos, ypos + ref.ypos);	// Point 타입의 pos라는 새로운 객체 생성, 두 개의 객체를 더하는 기능
		                                                //   => 연산자 오버로딩 : 내가 만든 타입의 객체를 연산함. (기본 연산자 : 기본자료형의 연산)
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);		// 객체 생성
	Point pos2(10, 20);		// 객체 생성
	Point pos3 = pos1.operator+(pos2);		// 대입연산자를 이용해서 객체 생성, 임시객체 생성 후 pos3에 전달. 
	Point pos4 = pos2.operator+(pos3);
	pos2.operator+(pos1);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();

	return 0;
}
