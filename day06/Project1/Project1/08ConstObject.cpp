#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) :num(n)
	{	}
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;	// 객체 자기자신 반환
	}
	void ShowData() const		// 상수화되어 있는 함수
	{
		cout << "num: " << num << endl;
	}
};

int main(void)
{
	const SoSimple obj(7);		// 객체 상수화
	// obj.AddNum(20);	// 객체가 const 이므로 사용하는 함수도 const이어야 한다. 변경할 소지가 있는 것조차 허용하지 않음.
	obj.ShowData();
	return 0;
}