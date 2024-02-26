#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class StudentClass
{
private:
	const int ID;			// 학번을 상수화 => 객체가 생성되기 전에 초기화를 시켜야됨.  
	char Name[20];
	char Major[20];
	int  Age;

public:
	StudentClass(int id, const char *pname, const char *pmajor, int age) : ID(id){ 
									  // <멤버 이니셜라이저> : 객체 생성시 초기화되지않는 멤버들을 초기화할때 사용.
									  // => 객체 생성과 상관없이 미리 초기화가 되는 멤버들의 초기화
									  // <문자열 입력받기>
									  // 문자열을 선언과 동시에 초기화하지 않았을 때 : 포인터로 배열에 접근
									  // 문자열이 변경되면 안되므로 const // strcpy()를 통하여 초기화 한다.
		//ID = id;					  		
		strcpy_s(Name, pname);        // strcpy => string copy의 줄임말, 
									  //함수는 어떤 변수(메모리) or 문자열 상수에 저장 되어있는 문자열을 다른 변수(메모리) 복사할 때 사용
									  // strcpy_s => strcpy함수의 단점을 보완하기 위해서 만들어진 함수
		strcpy_s(Major, pmajor);	  // strcpy(str1, str2) => str2를 str1에 저장한다.
		Age = age;					  // 문자열은 주소이므로 포인터 변수에 넣어서 사용한다. 문자열의 첫번째 문자 주소가 저장된다. 	
	}
	


	void ShowData()
	{
		cout << "학번: " << ID << endl;
		cout << "이름: " << Name << endl;
		cout << "전공: " << Major << endl;
		cout << "나이: " << Age << endl;
	}
};



int main(void)
{
	StudentClass student1(001, "이주희", "Iot", 26);	// 객체를 생성하면 생성자를 호출해야함. 생성자를 호출하는 코들
	student1.ShowData();								// 문자열이 저장된 주소를 사용 *pname
	return 0;
}



