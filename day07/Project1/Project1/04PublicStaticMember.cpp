#include <iostream>
using namespace std;

class SoSimple
{
public:		                    // ���� �����ڰ� public�̹Ƿ� �ܺο��� ���� ��� static ��������� �ܺο��� ����� �� �ְ� ����
	static int simObjCnt;		// static ������� ����(Ŭ���� ���)
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;	// static ��������� �ʱ�ȭ 

int main(void)
{
	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;	// 6���� ���п� Ŭ�����̸����� static ����� ���� ����
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;
	cout<<sim1.simObjCnt << "��° SoSimple ��ü" << endl;
	cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;
}