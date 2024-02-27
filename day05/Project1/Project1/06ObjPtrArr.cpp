/*
* 포인터 배열 : 포인터(주소값)를 저장하는 배열
* 배열 포인터 : 배열을 가리키는 포인터
*/

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(char* myname, int myage)	// 생성자 오버로딩
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person()		//디폴트 생성자
	{
		name = NULL;
		age = 0;
		cout << "Called Person()" << endl;
	}
	void SetPersonInfo(char* myname, int myage)
	{
		name = myname;
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ",";
		cout << "나이: " << age << endl;
	}
	~Person()
	{
		delete[]name;
		cout << "called destrutor!" << endl;
	}
};


int main(void)
{
	Person* parr[3];		// <객체포인터 배열> -배열의 주소를 저장하는 포인터 배열
	char namestr[100];
	int age;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;

		parr[i] = new Person(namestr, age); // 입력된 값을 가지고 Person이라는 객체를 힙영역에 생성.
	}

	parr[0]->ShowPersonInfo();			// . 은 클래스의 멤버를 직접 접근합니다.  ->은 포인터를 통해 데이터에 접근합니다.		
	parr[1]->ShowPersonInfo();			// 간접참조연산자는 포인터 객체가 멤버에 접근하기 위해 사용
	parr[2]->ShowPersonInfo();          // 직접참조연산자는 일반 객체가 멤버에 접근하기 위해 사용
									    // 객체포인터를 가지고 멤버에 접근 -> 
	
	delete parr[0];
	delete parr[1];
	delete parr[2];
	return 0;
}