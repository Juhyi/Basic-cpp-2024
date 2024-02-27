#include <iostream>
using namespace std;

class AA {
private:
	int a;
	int b;
public:
	AA(int a, int b) {			// int형 입력을 2개를 받는 생성자
		this->a = a;			// 자기 자신의 객체에게 접근
		this->b = b;
	}
	void AAInfo() {
		cout << a << " " << b << endl;

	}
};
int main()
{	
	AA obj1(10, 20);	// AA형의 객체 생성
	obj1.AAInfo();

	AA obj2(obj1);		// obj1을 복사하는 obj2 객체 생성 => 복사 생성자는 자동으로 호출되어짐. <디폴트 복사 생성자>
	obj2.AAInfo();


	return 0;
}