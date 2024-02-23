/*
*  C++ 타입의 구조체 : 구조체 멤버로 멤버변수와 멤버 함수를 가진다.
*/

#include <iostream>

typedef struct human {
	char name[20];			// C++ 타입 구조체 속성 : 멤버 변수{name, age, job} 
	int age;
	char job[20];

	void showHuman()		// c++ 타입 구조체 속성 : 멤버 함수를 가짐(기능)
	{
		printf("name: %s age: %d job: %s", name, age, job);
	}
}Human;


int main()
{
	int a;
	human h1 = { "홍길동", 50, "의적" };		
	h1.showHuman();	// showHuman의 메서드를 호출

	return 0;

}