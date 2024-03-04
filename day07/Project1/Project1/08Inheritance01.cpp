#include <iostream>
using namespace std;

class Person {
private:
	char name[50];  
	int age;
public:
	Person(int myage, const char* myname) {
		cout << "부모생성자 실행" << endl;
		age = myage;
		strcpy(name, myname);
	}
	void whatYourName() const {
		cout << "My name is " << name << endl;
	}
	void howOldAreYou() const {
		cout << "I'm " << age << "years old" << endl;
	}
};

class UnivStudent : public Person			// Person 클래스에 있는 것을 물려받음. class확장 총 필드 3개 사용 가능
{
private:
	char major[50];
public:
	UnivStudent(const char* myname, int myage, const char* mymajor)
		: Person(myage, myname)	// 부모생성자 
	{
		cout << "자식생성자 실행" << endl;
		strcpy(major, mymajor);
	}
	void whoAreYou() const
	{
		whatYourName();
		howOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{	
	UnivStudent obj("이주희", 26, "IoT");  // 3개의 필드를 사용하므로 입력도 3개. 
	obj.whoAreYou(); // 
	return 0; 
}