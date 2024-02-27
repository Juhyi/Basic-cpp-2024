#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	int num2;
public:
	
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
	{
		//empty
	}
	SoSimple(SoSimple& copy)         // 31행(SoSimple sim2 = sim1;) 객체 생성 과정에서 생성자 호출 자동으로 가능 <디폴트 복사 생성자> 
		:num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple(SoSimple & copy)" << endl;
	}
	void ShowSimpleDate()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1;							// => SoSimple sim2(sim1)으로 변환.
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleDate();
	return 0;
}