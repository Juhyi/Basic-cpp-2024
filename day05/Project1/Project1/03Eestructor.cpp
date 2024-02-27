#include <iostream>
#include<cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)		// 입력 2개를 갖는 생성자
	{
		int len = strlen(myname) + 1; // 문자열 길이 + 1 : 문자열인걸 나타내기 위해 문자들의 마지막에 NULL 문자를 붙여줌. 
		name = new char[len];
		cout <<"char의 크기: "<< sizeof(char) << endl;
		strcpy(name, myname);	// myname의 문자열과 name은 다른 것 
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~Person()		// 소멸자 - 자동호출됨 main에서 호출할 필요 없음. 객체가 2개이므로 소멸이 2번 발생.
	{
		delete[]name;		// 메모리를 할당받고 나서 반환해야하므로 자동 호출된 소멸자에서 반환하는 delete 사용.
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}