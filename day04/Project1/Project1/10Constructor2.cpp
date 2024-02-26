#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		num1 = n1;
		num2 = n2;
	}
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{
	SimpleClass sc1();				// 함수 선언, 출력에 해당 
	SimpleClass mysc = sc1();		// 생성된 객체로 mysc 초기화, 동일한 타입의 변수를 선언하여 리턴되는 객체를 저장
	mysc.ShowData();				// 객체에 있는 함수 호출
	return 0;
}

SimpleClass sc1()
{
	SimpleClass sc(20, 30);			// 객체 생성하는 코드 (자동으로 호출)
	return sc;						// sc 객체로 리턴
}