#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt;	// static �������, Ŭ���� ����: ��ü�� �����ϴ��� ������ �޸� ������ �� �ϳ��� ���� �Ǿ� �����Ǵ� ����
public:						// static ��������� ��ü ���� �����ϴ� ���� �ƴ�. But �������ó�� ������ �� �ִ� ������ ����.
	SoSimple()				// static **��ü�� ��� ��.  static ����Լ� �������� static ��������� static ����Լ��� ȣ���� �����ϴ�.
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};
int SoSimple::simObjCnt = 0;		// static ��������� �ʱ�ȭ, �̹� �޸� ������ �Ҵ�� �����̹Ƿ� �ܺο��� �ʱ�ȭ�� �̷����.
			
class SoComplex
{
private:
	static int cmxObjCnt;		// �ܺ��� ���� �����Ͽ� �ٸ� �������� �߸� �����ϴ� ���� �߻����� ����.
public:
	SoComplex()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplex ��ü" << endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° &SoComplex ��ü" << endl;
	}
};
int SoComplex::cmxObjCnt = 0;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();		// �ӽð�ü  ����, �̸����� ��ü ������. 
	return 0;
}