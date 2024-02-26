#include <iostream>
using namespace std;

class MyClass {
	int num;

public:
	MyClass() {  // 생성자 함수
		cout << "생성자 호출: MyClass()" << endl;
		num = 10;
	}
	MyClass(int anum) {		// 생성자 오버로딩
		cout << "생성자 호출: MyClass(int)" << endl;
		num = anum;
	}
	void MyClassInfo() {
		cout << "num:  " << num << endl;
	}
};

int main() {

	MyClass* m = new MyClass();  // new로 생성자 만들고 호출, 포인터 변수 m에 주소를 저장하여 사용.
	MyClass m1; // 객체를 생성, 생성자가 자동으로 호출됨. 객체 생성 명령으로 생성자는 자동 호출 됨.
	//MyClass m2();  // 메서드 호출, 객체 생성이 안됨. 
	m1.MyClassInfo(); 
	MyClass m2(20);  // 20의 매개변수를 받을 생성자가 있기 때문에 사용 가능
	m2.MyClassInfo();


	return 0;
}

// 생성자를 호출하지 않으면 defalt 생성자가 자동으로 만들어짐. 디폴트 생성자 => 입력을 받지 않는 생성자

