#include <iostream>
#include <cstdio>
using namespace std;
#define _CRT_SECURE_NO_WARNING

class Person
{private:
	char* name;				// 객체를 생성해야 멤버함수, 필드를 사용할 수 있음.  								
	int age;				// 멤버변수, 멤버함수는 객체 꺼임.
public:
	Person(const char* pname, int aage) :age(aage)
	{
		name = new char[strlen(pname) + 1];		//new 연산자를 이용해서 힙영역에 메모리를 할당하여 저장
		strcpy(name, pname); 
		
	}
	Person(const Person& a) :age(a.age)			// 힙영역에서 메모리를 소멸할때 문제가 생기므로 객체를 복사한 후 소멸자 호출
	{
		this->name = new char[strlen(a.name + 1)];		
		strcpy(name, a.name);							
		this->age = a.age; ;
	}
	void personInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	
};



int main()
{
	Person p("이주희", 26);
	p.personInfo();
	
	Person copyp(p);
	copyp.personInfo();

	return 0;
}