#include <iostream>
#include <string.h>
#include <stdlib.h>

//#define _CRT_SECURE_NO_WARNINGS

using namespace std;


char* MakesStrAdr(int len)
{	
	char* str = (char*)malloc(sizeof(char) * len);	//c: heap영역에 20Byte 크기로 메모리 할당
	printf("char size: %llu\n", sizeof(char));		// 12줄:  str 포인터 변수 주소값을 저장
	return str;
}

int main(void)
{
	char* str = MakesStrAdr(20);
	strcpy(str, "I am so happy~"); // 문자열을 저장해라
	cout << str << endl;
	free(str); // 힙 영역에 할당된 메모리 공간 해제
	return 0;
}
