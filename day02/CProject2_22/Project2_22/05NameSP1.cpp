#include <iostream>
using namespace std;

namespace BestComImpl  // BestComImpl의 이름의 namespace 공간에  SimpleFunc()이 저장
{
	void SimpleFunc(void)
	{
		cout << "BestCom이 정의한 함수" << endl;
	}
}

namespace ProgrComImpl
{
	void simpleFunc(void)
	{
		cout << "Program이 정의한 함수" << endl;
	}
}

int main(void)
{
	BestComImpl::SimpleFunc();  // SImpleFunc()이 저장되어 있는 BestComImpl 공간을 먼저 알려주고 호출해야함.
	ProgrComImpl::simpleFunc(); // ProgramComImpl 안에 있는 simpleFunc()을 호출하겠다.
	return 0;
}