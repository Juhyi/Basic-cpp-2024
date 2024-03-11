#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{  }
	void ShowData() { cout << num1 << ", " << num2 << endl; }
	/*
	First& operator=(const First& ref)
	{
		cout << "First& operator=()" << endl;
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}*/
};

class Second : public First			// 자식 클래스의 생성자에는 명시를 하지 않아도 기초 클래스의 생성자가 호출됨.
{									// But, 자식 클래스의 대입연산자에는 아무런 명시를 하지 않으면, 부모 클래스의 대입 연산자가 호출되지 않음
private:
	int num3, num4;
public:
	Second(int n1, int n2, int n3, int n4)
		: First(n1, n2), num3(n3), num4(n4)
	{  }
	void ShowData()
	{
		First::ShowData();
		cout << num3 << ", " << num4 << endl;
	}

	
	Second& operator=(const Second &ref)			// 부모클래스의 대입연산자도 정의해주어야 호출 가능함. 얕은 복사의 경우 생각할 필요 X
	{												// 깊은 복사일 경우에만 정의해주면 된다. 
		cout<<"Second& operator=()"<<endl;
		First::operator=(ref);				// (부모클래스의 대입연산자를 주석해도) 부모클래스의 디폴드 대입 연산자가 호출됨
		num3=ref.num3;						// 주석 처리하지 않으면 명시적으로 정의된 대입연산가 호출되어 "First& operator=()" 출력됨.		
		num4 = ref.num4;					// First::operator=(ref); => 부모클래스의 값을 받기 위해 선언. 	
		return *this;
	}
	

};


int main(void)
{
	Second ssrc(111, 222, 333, 444);
	Second scpy(0, 0, 0, 0);
	scpy = ssrc;
	scpy.ShowData();
	return 0;
}