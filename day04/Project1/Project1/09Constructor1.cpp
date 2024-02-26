#include <iostream>
using namespace std;

class SimpleClass
{
private:
	int num1;
	int num2;
public:
	/*
	SimpleClass()			// 디폴트 생성자
	{
		num1 = 0;
		num2 = 0;
	}
	/*
	SimpleClass(int n)		// 생성자 오버로딩
	{
		num1 = n;
		num2 = 0;
	}
	SimpleClass(int n1, int n2)
	{
		num1 = n1;
		num2 = n2;
	}
	/*
	SimpleClass(int n1 = 0 ,int n2 = 0)  // 매개변수를 초기화, 디폴트 매개변수, 입력이 없는 경우 디폴트 값이 들어감
	{									//  얘가 있어도 기본 생성자는 필요함.	
		num1 = n1;
		num2 = n2;
	}

	// 디폴트 매개변수를 사용할 경우 모호해지는 경향이 있어 조심해야함.
	*/
	
	void ShowData() const
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{
	SimpleClass sc1;	// 객체 생성 
	sc1.ShowData();
	/*
	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(100, 200);
	sc3.ShowData();
	*/
	return 0;
}