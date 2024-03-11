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
	Number& operator=(const Number& ref)		// 대입연산자 오버로딩
	{
		cout << "operator=()" << endl;			// 문자열 출력
		num = ref.num;								
		return *this;
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num;
	num = 30;				// 서로 다른 두 자료형의 피연산자를 대상으로 대입연산을 진행함. 
	num.ShowNumber();		// num = 10 => 1. num = Number(30); -> num.operator =(Number(30)) : 임시객체 생성 후 임시객체를 대상으로 하는 대입 연산자를 호출
	return 0;				// : int형 데이터를 인자로 전달받는 Number 클래스의 생성자 호출을 통해 Number형 임시객체를 생성한 후,  
}							//   두 Number 객체를 대상으로 대입연산 진행
