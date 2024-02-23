/*
*  C 타입의 구조체 : 멤버로 멤버 변수만 가짐
*/
#include <stdio.h>

typedef struct human {			// human 구조체 선언 <struct 구조체 이름 {멤버변수 선언};>
								// 내가 만든 사용자 정의 자료형 : human 구조체	
	char name[20];		// C타입 구조체 속성 : 멤버 변수{name, age, job} 선언만 가짐
	int age;
	char job[20];
}Human;				// 앞으로 human 구조체를 Human으로 사용한다.

void showHuman(Human h)
{
	printf("name: %s age: %d job: %s\n", h.name, h.age, h.job); // %s : 서식문자 (s => 문자, d => 숫자 )
}


int main()
{
	int a;
	human h1 = { "홍길동", 50, "의적" };		//Human 타입의 변수를 선언하고 초기화를 시킨다.
	showHuman(h1);

	return 0;

}