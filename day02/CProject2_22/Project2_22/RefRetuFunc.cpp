#include <iostream>
using namespace std;

int& FuncOne(int n)
{
	int num = 20;
	num += n;
	return num;		// num =30   
}
int main(void)
{
	int &ref = FuncOne(10);	// ref = 30, num �� �������� �̹Ƿ� main���� ���� ��ȯ���� main���� �������. 

	return 0;
}