#include <iostream>
#include <string.h>


//#define _CRT_SECURE_NO_WARNINGS

using namespace std;


char* MakesStrAdr(int len)
{
	//char* str = (char*)malloc(sizeof(char) * len);	
	char* str = new char[len];		// c++: �� ������ len ũ�⸸ŭ �޸� ���� �Ҵ�, ��ü�� heap������ �Ҵ�
	return str;						// ���� ������ �ִ� ������ ������ �����ؼ� heap ������ �ּҰ� ����
}									//	new Ű���� - �� ������ �����ϱ� ���ؼ��� new�� ����ؾ���.

int main(void)
{
	char* str = MakesStrAdr(20);
	strcpy(str, "I am so happy~"); 
	cout << str << endl;
	//free(str);
	delete[]str;		// c++ : �Ҵ���� �޸� ��ȯ
	return 0;
}

// Ŭ���� �ȿ��� �Լ� ���� => �ż���, �Լ� �̸��� Ŭ������ ����: ������