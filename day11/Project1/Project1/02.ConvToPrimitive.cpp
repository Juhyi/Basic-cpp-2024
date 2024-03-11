#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	operator int()    // 형 변환 연산자의 오버로딩
	{
		return num;			// 반환형이 없는데 반환을 함.
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num1;
	num1 = 30;

	Number num2 = num1 + 20;		// num1 + 20이 선행되어야 하는데 operator+가 정의되어 있지 않음 => num1을 형변화 -> 형변환 연산자 호출
	num2.ShowNumber();
	return 0;
}
