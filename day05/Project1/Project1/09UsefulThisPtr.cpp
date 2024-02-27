#include <iostream>
using namespace std;

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1;			// this->num1은 멤버 변수이고 num1은 매개 변수이다. 
		this->num2 = num2;			// this 로 자기 자신 객체에 접근하여 매개 변수 값 대입받음.
	}
	/*
	TwoNumber(int num1, int num2)
		: num1(num1), num2(num2)
	{
		// empty
	}
	*/
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowTwoNumber();
	return 0;
}