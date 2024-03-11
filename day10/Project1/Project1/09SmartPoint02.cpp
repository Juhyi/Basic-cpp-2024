#include<iostream>

class MyClass {
	int* ptr;
public:
	MyClass(int p) : ptr(new int[100]){  // int 타입의 방 100개를 가지는 객체를 초기화
		printf("생성자 호출\n");
	}
	~MyClass() { 
		printf("소멸자 호출\n");
		delete[] ptr;
	}
};
int main()
{
	MyClass* m1 = new MyClass(10);
	std::cout<< "===================================" << std::endl;
	std::unique_ptr<MyClass>m2(new MyClass(20));  // 소멸자 자동으로 호출 => 스마트 포인터
	     // unique_ptr<타입> => 스마트 포인터 
	return 0;
}