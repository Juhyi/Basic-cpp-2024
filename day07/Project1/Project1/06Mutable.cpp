#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2;		//mutable로 선언을 하면 const 함수 내에서도 값이 변경 가능하다. 
public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
	{ }
	void ShowSimpleData() const		// const 함수
	{
		cout << num1 << ", " << num2 << endl;
	}
	void CopyToNum2() const
	{
		num2 = num1;
	}
};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();
	return 0;
}