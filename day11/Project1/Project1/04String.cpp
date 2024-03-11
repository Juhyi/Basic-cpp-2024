#include <iostream>
using namespace std;
/*
* C-Style 문자열
* 문자열은 마지막에 널 문자가 붙는다.
*/
int main()
{
	/*
	int  code = 97;
	cout << code << endl;
	cout << char(code) << endl;
	cout << "==================================" << endl;
	char arr[6] = { 'a', 'b', 'c', 'd','e' };  // 문자열 타입의 배열 선언
	cout << arr << endl;
	cout << "==================================" << endl;
	char arr1[] = { 'a', 'b', 'c', '\0','e' };  // 널문자 :문자열의 끝을 알림
	cout << arr1 << endl;
	cout << sizeof(arr1) << endl;	// 전체 문자 크기
	cout << strlen(arr1) << endl;	// 문자열의 크기 : 널문자 앞의 크기
	cout << "==================================" << endl;
	char str[] = "string";	 // 스택에 배열을 만들어서 집어넣기 때문에		// 자동으로 널문자가 붙는다
	cout << str << endl;
	cout << sizeof(str) << endl;	// 문자열: 널 문자가 포한된 크기가 붙음	
	cout << strlen(str) << endl;	// 순수한 문자의 크기
	str[0] = 'S';
	cout << str << endl;
	cout << "==================================" << endl;
	const char* pstr = "string";		// 변경이 안되기 때문에 const 붙여줌
	cout << pstr << endl;				// 포인터는 주소에 저장 
	cout << sizeof(pstr) << endl;	// 8	
	cout << strlen(pstr) << endl;	// 6	
	// pstr[0] = 's';    : 문자열을 포인터로 사용하는 경우는 변경이 불가능하다. 
						

	*/

/*
* C++ -style
*/
string s = "string";
cout << s << endl;
cout << sizeof(s) << endl;	// string 타입의 크기는 기본적을 40
// cout << strlen(s) << endl;
cout << s.size() << endl;		// 입력한 크기를 알고 싶으면 멤버함수 s.size() 사용

string s1 = "Hongkildon";
cout << s1 << endl;
cout << sizeof(s1) << endl;
cout << s1.size() << endl;		// 입력한 크기를 알고 싶으면 멤버함수 s1.size() 사용
cout << s1.capacity() << endl;

string s1 = "Hi";
string s2 = "you";

string s3 = s1 + s2;
cout << s3 << endl;

return 0;

}