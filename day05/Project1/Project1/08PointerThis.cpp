#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int num) 
	{	
		this->num = num;					// this는 객체 자신의 주소값을 의미
		cout << "num=" << num << ", ";
		cout << "address=" << this << ", ";	// This는 객체의 자기자신을 가리킴.매개변수 이름을 따로 하지 않아도 됨 this는 포인터이므로 -> 사용
	}
	void ShowSimpleData()		// 멤버 함수는 변수를 한번만 생성하고 그 이후에는 처음에 만들어진 기존의 멤버 변수를 공유한다.
	{							
		cout << num << endl;
	}
	SoSimple* GetThisPointer()
	{
		return this;
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();						

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}