/*
*  C++ 클래스 : 클래스 멤버로 멤버변수와 멤버 함수를 가진다.
*/
#include <iostream>

class human {		// 내가 만든 사용자 정의 자료형 : human class
public:
	char name[20];			// 속성 : 멤버 변수{name, age, job} 
	int age;
	char job[20];

	void showHuman()		// 속성 : 멤버 함수를 가짐(기능)
	{
		printf("name: %s age: %d job: %s", name, age, job);
	}
}Human;


int main()
{
	int a;
	// human h1 = { "홍길동", 50, "의적" };
	// h1.showHuman();	// showHuman의 메서드를 호출
	human h1 = { "홍길동", 50, "의적" };	//Human 타입의 변수를 선언하고 초기화를 시킨다.
	h1.showHuman();



	return 0;

}