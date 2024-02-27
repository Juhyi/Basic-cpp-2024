#include <iostream>
using namespace std;

class AA {
private:
	int a;
	int b;
public:
	AA(int a, int b) {
		this->a = a;
		this->b = b;
	}
	
	AA(const AA & ref){
		this->a = ref.a;
		this->b = ref.b;
		cout << "복사 생성자 호출" << endl;
	}


	void AAInfo() {
		cout << a << " " << b << endl;
	}
};

int main(void) {

	AA obj1(10, 20);
	obj1.AAInfo();

	AA obj2(obj1);
	obj2.AAInfo();

	return 0;
}