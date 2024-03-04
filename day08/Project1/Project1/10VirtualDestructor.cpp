#include <iostream>
using namespace std;

class First
{
private:
	const char* strOne;
public:
	First(const char* str)
	{
		strOne = new char[strlen(str) + 1];		//new 사용하여 동적할당
	}
	virtual ~First()		// 소멸자 정의
	{
		cout << "~First()" << endl;
		delete[]strOne;
	}
};

class Second : public First
{
private:
	const char* strTwo;
public:
	Second(const char* str1, const char* str2) : First(str1)	
	{
		strTwo = new char[strlen(str2) + 1];	// 동적할당
	}
	virtual ~Second()							// virtual 소멸자를 정의하면 객체를 가리키므로 순차적으로 소멸자가 실행된다.  
	{											// 소멸순서 : 자식 -> 부모
		cout << "~Second()" << endl;
		delete[]strTwo;
	}
};

int main(void)
{
	// 상속관계에 있어서 객체포인터는 조심해야함. 부모타입의 객체포인터로 자식 객체를 가리키는 경우(다형성) 조심하기 ** 
	First* ptr = new Second("simple", "complex");	// First 타입의 ptr 포인터변수로 객체 생성
	delete ptr;		// 객체 소멸을 ptr 포인터로 명령-> First 클래스의 소멸자만 호출되어짐. 메모리 누수 발생. 
	return 0;		// 객체 소멸 과정에서는 delete 연산자에 사용된 포인터 변수의 자료형에 상관없이 모든 소멸자가 호출되어야함.
					// 그러므로 virtual 소멸자를 사용하여 모든 소멸자 호출.
}		