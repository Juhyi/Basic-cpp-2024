#include <iostream>
using namespace std;

namespace BestComImpl  // BestComImpl�� �̸��� namespace ������  SimpleFunc()�� ����
{
	void SimpleFunc(void)
	{
		cout << "BestCom�� ������ �Լ�" << endl;
	}
}

namespace ProgrComImpl
{
	void simpleFunc(void)
	{
		cout << "Program�� ������ �Լ�" << endl;
	}
}

int main(void)
{
	BestComImpl::SimpleFunc();  // SImpleFunc()�� ����Ǿ� �ִ� BestComImpl ������ ���� �˷��ְ� ȣ���ؾ���.
	ProgrComImpl::simpleFunc(); // ProgramComImpl �ȿ� �ִ� simpleFunc()�� ȣ���ϰڴ�.
	return 0;
}