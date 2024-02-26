#include <iostream>
#include <string.h>


//#define _CRT_SECURE_NO_WARNINGS

using namespace std;


char* MakesStrAdr(int len)
{
	//char* str = (char*)malloc(sizeof(char) * len);	
	char* str = new char[len];		// c++: 힙 영역에 len 크기만큼 메모리 공간 할당, 객체를 heap영역에 할당
	return str;						// 스택 영역에 있는 포인터 변수를 생성해서 heap 영역의 주소값 저장
}									//	new 키워드 - 힙 영역에 저장하기 위해서는 new를 사용해야함.

int main(void)
{
	char* str = MakesStrAdr(20);
	strcpy(str, "I am so happy~"); 
	cout << str << endl;
	//free(str);
	delete[]str;		// c++ : 할당받은 메모리 반환
	return 0;
}

// 클래스 안에서 함수 정의 => 매서드, 함수 이름은 클래스랑 동일: 생성자