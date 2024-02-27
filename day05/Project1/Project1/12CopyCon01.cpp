/*
* 복사 생성자
* - 객체를 복사할때 호출되는 생성자
* - 따라서 복사할 객체를 입력으로 가져야하는데 이때 원본 객체의 참조를 입력으로 받음 => 또 다른 메모리 공간이 필요하지 않다.
*/
#include <iostream>
using namespace std;

class AClass {
public:
	AClass(){
		cout << "디폴트 생성자 호출" << endl;
	}
	AClass(int n){
		cout << "AClass(int n) 생성자 호출" << endl;
	}
	AClass(const AClass & r) {		// 복사 생성자, & 참조가 없다면 객체를 입력으로 받아 복사 생성자가 무한 생성되어짐. & 참조로 받아야함.
									// 원본의 값이 변경되면 안되기 때문에 const를 붙여야함. 
		cout << "AClass(const AClass & r) 생성자 호출" << endl;

	}


};

void func(int a) {		// n =10과 a=10 은 다르다. 복사 생성자 &이 없을때 일어나는 것 설명하기 위한 개념.
	a++;
}


int main(void)
{	
	int n = 10;
	AClass obj1;				// 디폴트 생성자로 객체 생성
	AClass obj2(10);			// int형 입력을 1개 가지는 생성자 호출
	AClass obj3(obj2);			// 복사 생성자 호출
	func(n);
	return 0;
}