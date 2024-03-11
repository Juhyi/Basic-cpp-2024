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
	Point& operator++()		// 멤버함수로 정의된 연산자 오버로딩, 전위증가 - 증가하고 값을 값을 줌 a = ++1 => 증가한걸 대입 a = 2
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	const Point operator++(int)		// 멤버함수로 정의된 연산자 오버로딩, 후위증가 - 값을 주고 증가, int는 후위연산을 표현하기 위한 것일 뿐 의미 없음. 
	{  // 1. 현재의 객체를 복사하여 현재의 속성값을 유지시킴																		//  a = i++, i값을 a에 대입한 후 i + 1 증가.		
		const Point retobj(xpos, ypos);   // const Point retobj(*this);, 값을 증가시키기 전에 반환을 할 복사본을 생성, 복사본의 값이 변경되지 않도록 const
		// 2. 현재 객체의 속성값을 1씩 증가시킨다. 
		xpos += 1;
		ypos += 1;
		return retobj;			// 3. 멤버의 값이 증가하기 이전의 복사본을 반환 => 후위증가의 효과
	}
	friend Point& operator--(Point& ref);				// friend로 선언
	friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref)		// 전역함수로 선언된 연산자 오버로딩, 전위감소
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point operator--(Point& ref, int)		// 전역함수로 선언된 연산자 오버로딩, 매개변수의 선언에 int형 추가-> 후위감소
{
	const Point retobj(ref);		// return되는 retobj을 const화 retobj는 함수를 벗어나면 소멸, 임시객체가 만들어짐.
	ref.xpos -= 1;					// 임시객체가 const이기 위해서 함수의 출력을 const화 해줌.
									// const 함수 내에서는 const 함수의 호출만 허용하도록 제한.	
	ref.ypos -= 1;					// const도 타입의 종류, const 유무로 오버로딩이 가능.
	return retobj;
}

int main(void)
{
	Point pos(3, 5);
	Point cpy;
	cpy = pos--;			// 후위 감소를 나타냄. --는 전역변수로 정의된 연산자 오버로딩 : operator--(pos)의 의미 
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++;			// 후위 증가를 나타냄. ++은 멤버함수로 정의된 연산자 오버로딩 : pos.operator++()의 의미
	cpy.ShowPosition();
	pos.ShowPosition();
	return 0;
}

Point pos(3, 5);
//(pos++)++;  // 후위 증가임으로 임시 객체를 전달받음. 임시 객체가 const이므로 증가시킬 수 없기 때문에 컴파일 에러. 
//++(++pos);  // 전위 증가는 자기 것을 반환하고 const도 아니므로 컴파일 에러가 나지 않음. 