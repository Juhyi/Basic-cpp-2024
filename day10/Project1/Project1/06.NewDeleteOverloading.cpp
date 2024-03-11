#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { printf("생성자 호출\n"); } // 메모리 할당 후 객체 생성됨.
	friend ostream& operator<<(ostream& os, const Point& pos);

	void* operator new (size_t size)
	{
		cout << "operator new : " << size << endl;   // size는 컴파일러가 알아서 정함
		void* adr = new char[size];					// 필요한 메모리 공간 할당
		return adr;
	}

	void operator delete (void* adr)
	{
		cout << "operator delete ()" << endl;
		delete[]adr;							// 배열의 형태로 할당햇기 대문에 배열의 삭제를 위한 delete문을 구성
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point* ptr = new Point(3, 4);		// new 연산자로 객체 생성, 생성자 호출
	cout << *ptr;
	delete ptr;
	return 0;
}
