#include <iostream>
using namespace std;

class Person
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person
{
public:
	void Sleep() { cout << "Student Sleep" << endl; }
	void Study(){ cout << "Study" << endl; }
};

class PartTimeStudent : public Student
{
public:
	void Work() { cout << "Work" << endl; }			// 멤버 함수, 메스드를 3개 가지고 있음
};

int main(void)
{
	Person* ptr1 = new Student();				//	 Student *ptr = new Student : 원칙은 동일한 타입을 사용하는 것.
	Person* ptr2 = new PartTimeStudent();		// 부모타입의 객체 포인터로 자식 객체을 가리키고 있는 것 (상속 관계이기 때문에 가능한 것)
	Student* ptr3 = new PartTimeStudent();		// 하지만 자식타입의 객체 포인터로 부모 객체를 가리킬 수는 없다.
	ptr1->Sleep();							// 그리고 ** 접근 객체 포인터 타입을 따른다.  객체 포인터 이므로 간접 참조를 통해 접근한다. 
	ptr2->Sleep();
	ptr3->Study();
	ptr3->Sleep();		//	 접근 객체의 포인터 타입을 따르므로 Student class의 Sleep을 참조함. 
	delete ptr1;	delete ptr2;	delete ptr3;
	return 0;
}

// 24행 : Student는 Person을 상속하므로 Person형 포인터 변수는 Student 객쳉를 가리킴. 
// 상속 관계에서 동일한 이름의 함수 => 오버라이딩 -> 나중에 다시 공부

/*
* 오버로딩(Overloading) -다중정의
* 오버라이딩(Overrideng) - 재정의, 상속관계에서 사용
*/