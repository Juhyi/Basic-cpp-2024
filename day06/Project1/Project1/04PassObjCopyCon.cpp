#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n):num(n)
	{
		cout << "Called SoSimple(int n) constructor" << endl;
	
	}
	SoSimple(const SoSimple& copy) : num(copy.num)   // Copy => obj  num => ob
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	void ShowData()						// 멤버함수 --> 객체 생성 후 사용 가능.
	{
		cout << "num: " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob)    // 어디에도 소속된지 않은 전역 함수. --> 어디에서든 누구든 바로 접근 가능. 
{
	ob.ShowData();				//  SoSimple의 멤버함수 호출 
}

int main(void)
{
	SoSimple obj(7);
	cout << "함수호출 전" << endl;
	SimpleFuncObj(obj);
	cout << "함수호출 후" << endl;
	return 0;
} 