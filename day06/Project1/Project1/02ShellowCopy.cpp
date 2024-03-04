#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		cout << "생성자 호출" << endl;
		int len = strlen(myname) + 1;
		name = new char[len];
	}
	Person(const Person& other) :age(other.age)		// 복사 생성자
	{	
		cout << "깊은 복사생성자 호출" << endl;

		// this->name =other.name;    // 얕은 복사
		// this->age = other.age; 
		this->name = new char[strlen(other.name + 1)];		// 메모리 공간 할당 후 문자열을 복사하고 할당된 메모리 주소값을 멤버 name에 저장. 
		strcpy(name, other.name);							// 객체 별로 각각 문자열을 참조 => 포인터로 참조하는 대상까지 깊게 복사함. : 깊은 복사
		this->age = other.age;			// 멤버대 멤버 복사
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()					
	{							
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 20);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}