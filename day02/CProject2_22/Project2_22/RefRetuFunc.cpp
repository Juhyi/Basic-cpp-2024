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
	int &ref = FuncOne(10);	// ref = 30, num 은 지역변수 이므로 main에서 받을 반환값이 main에서 사라진다. 

	return 0;
}