#include <iostream>
using namespace std;

namespace BestComImpl			// ����
{
	void SimpleFunc(void);		// SimpleFunc�� BestCom�� namespace�� ����� �Լ�
}

namespace ProgrComImpl
{
	void SimpleFunc(void); // SimpleFunc�� ProgrCom�� namespace�� ����� �Լ�
}

int main(void)
{
	BestComImpl::SimpleFunc();    // SimpleFunc �̸��� ������ namespace�� �ٸ��Ƿ� �ٸ� �Լ���.
	ProgrComImpl::SimpleFunc();	// :: => ���� ������ // namespace ���� �ۿ��� ȣ��, ���Ǹ� �Ҷ��� �տ� :: ���� �������� ���༭ ����� �Լ����� �˷��ֱ�
	return 0;
}

void BestComImpl::SimpleFunc(void)
{
	cout << "BestCom�� ������ �Լ�" << endl;
}


void ProgrComImpl::SimpleFunc(void)
{
	cout << "ProgrCom�� ������ �Լ�" << endl;
}