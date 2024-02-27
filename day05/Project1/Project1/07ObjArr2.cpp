/*
* 객체 배열
*/
# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
using namespace std;

class Human {
private:
	char name[30];
	int age;

public:
	Human(const char* pname, int aage)
	{
		cout << "생성자 호출" << endl;
		strcpy(name, pname);
		age = aage;
	}
	void HumanInfo() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;

	}

	~Human()
	{
		
		cout << "소멸자 호출" << endl;
	}


};


int main() 
{
	Human h[3] = { Human("홍길동", 50), Human("이주희", 26), Human("오재경", 29) };		// 객체 배열

	for (int i = 0; i < 3; i++) {

		h[i].HumanInfo();				

	}

	Human* h1 = new Human("바보", 50);  // 힙 영역에 객체 생성, 포인터 변수 h1으로 주소값 전달받음
	h1->HumanInfo();					// h1은 포인터 객체 이므로 간접 참조 -> 를 통해 데이터에 접근 
										// 객체포인터가 가리키는 멤버에 접근
	Human h2("멍청이", 20);
	h2.HumanInfo();                     // 일반 객체 이므로 직접 참조 . 를 통해 데이터에 접근, 포인터가 아닌 집적적인 객체를 참조
	return 0;
}