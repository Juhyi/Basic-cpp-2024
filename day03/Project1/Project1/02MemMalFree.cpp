#include <iostream>
#include <string.h>
#include <stdlib.h>

//#define _CRT_SECURE_NO_WARNINGS

using namespace std;


char* MakesStrAdr(int len)
{	
	char* str = (char*)malloc(sizeof(char) * len);	//c: heap������ 20Byte ũ��� �޸� �Ҵ�
	printf("char size: %llu\n", sizeof(char));		// 12��:  str ������ ���� �ּҰ��� ����
	return str;
}

int main(void)
{
	char* str = MakesStrAdr(20);
	strcpy(str, "I am so happy~"); // ���ڿ��� �����ض�
	cout << str << endl;
	free(str); // �� ������ �Ҵ�� �޸� ���� ����
	return 0;
}
