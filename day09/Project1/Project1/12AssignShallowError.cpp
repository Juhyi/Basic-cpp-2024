#include <iostream>
#include <cstring>
using namespace std;

class Person
{
	char* name;
	int age;
public:
	Person(const char* myname, int myage)		// 생성자 정의
	{
		int len = strlen(myname) + 1;
		name = new char[len];			// new를 사용하여 힙영역에 동적할당
		strcpy(name, myname);
		age = myage;
	}
	
	Person& Person::operator=(const Person& ref)
	{
		delete []name;		// 메모리의 누수를 막기 위한 메모리 헤제 연산과정을 거치기 (2)

		int len=strlen(ref.name)+1;
		name= new char[len];
		strcpy(name, ref.name);
		age=ref.age;
		return *this;
	}
	

	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~Person()			// 소멸자가 한번 만 호출되므로 문제 발생
	{
		delete[]name;							// delete를 이용한 메모리 해제 
		cout << "called destructor!" << endl;	// man2가 소멸되고 남아있는 man1의 객체가 소멸할 차례일때 name이 가리키는 문자열은 이미 소멸되어있음. (man2 객체 소멸시 소멸)
	}											// => 이미 소멸된 문자열을 재소멸하는 문제가 생김
};

int main(void)
{
	Person man1("Lee dong woo", 29); 
	Person man2("Yoon ji yul", 22);
	man2 = man1;			// man1에 man2를 대입 => 디폴트 대입연산자 호출 => man1과 man2는 동일한 주소값을 가짐 (하나의 문자열을 두 개의 객체가 동시에 참조)=> 얕은 복사를 함
							// 문자열 "Yoon ji yul"을 가리키던 문자열의 주소 값을 잃게 됨. => 문자열에 접근 불가능 (메모리 누수 발생) 
	man1.ShowPersonInfo();	// -> 얕은 복사시 힙 영역에서 생성한 객체 소멸과정에서 중복소멸하는 문제가 생김.
	man2.ShowPersonInfo();
	return 0;
}

/*
* 생성자 내에서 동적할당을 할 경우, 디폴트 대입 연산자는 2가지 문제를 발생 시킴.
* =>해결방법: 1. 깊은 복사를 진행하도록 정의
*			  2. 메모리 누수가 발생하지 않도록, 깊은 복사에 앞서 메모리 헤제의 과정 거치기.
*/