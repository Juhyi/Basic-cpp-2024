#include <iostream>
using namespace std;

class AAA
{
private:
	int num;

private:
	AAA(int n) : num(n) {

	}
public:
	AAA():num(0){}

	~AAA() {};  //소멸자 ~을 붙이면 끝, 오버로딩 안됨, 입력값 없음
	AAA& CreateInitObj(int n) const
	{
		AAA* ptr = new AAA(n);	// 객체 생성
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }

};

int main(void)
{
	// AAA a(10);		// private롤 생성자가 만들어져있음, 외부에서 생성 못함 => 객체를 1번만 생성할 수 있음. 싱글톤 패턴 -> 메모리 절약
						// 객체의 변수를 공유하는 경우																			

	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3); // obj1,2는 다른객체  27번 줄에서 객체 1개 생성, 29번줄에서 객체 1개 생성
	obj1.ShowNum();


	AAA& obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;
	return 0;

}