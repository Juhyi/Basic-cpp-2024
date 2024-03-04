#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "New Object: " << this << endl;  // this ��ü �ڱ��ڽ��� �ּҰ�, this�� ������ �̹Ƿ�.  => ��ü obj�� �ּ�
	}
	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "New Copy Object: " << this << endl;  // ��ü�� �����Ǹ鼭 ���� ������ ȣ��, ��ü ob�� �ּ� ���
	}
	~SoSimple()
	{
		cout << "Destroy object" << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)		//  SoSimple Ÿ���� ������ϴ� �Լ� ob�� obj�� �����Ͽ� ��ü ����
{
	cout << "Parm ADR: " << &ob << endl;	// �ּ� ������ &�� ����Ͽ� ob�� �ּ� ���
	return ob;		// ��ü ob�� ��ȯ�ϹǷ� �ӽð�ü ������. ���� �� ������� �����Ƿ� �Ҹ��. ob�� �Լ��� ����鼭 �Ҹ�ǹǷ� 
					// ob ��ü �Ҹ� �� �ӽð�ü�� �Ҹ��.
}				

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);
	cout << "Return Object" << &tempRef << endl;
	return 0;

}

/*
New Object: 0000002946FEFB44      : ��ü obj �ּ�
New Copy Object: 0000002946FEFC44 : ��ü ob �ּ�
Parm ADR: 0000002946FEFC44		  : ��ü ob �ּ�
New Copy Object: 0000002946FEFC84 : �ӽ� ��ü �ּ�
Destroy object0000002946FEFC44    : ��ü ob �Ҹ�
Destroy object0000002946FEFC84    : �ӽð�ü �Ҹ�

New Copy Object : 0000002946FEFCA4 : ��ü ob �ּ� - main �Լ����� SoSimple ��ü obj�� ������ ���� �ּ�, ��ü ob �ּ�
Parm ADR : 0000002946FEFCA4		   : ��ü ob �ּ� - SimpleFuncObj �Լ� ������ SoSimple ��ü ob�� ������ ���� �ּ�(�Ű������� ���� ��ü�� �ּ�)  
New Copy Object : 0000002946FEFB64 : �ӽð�ü �ּ� - SimpleFuncObj �Լ� ������ SoSimple ��ü ob�� �����Ͽ� ���ο� ��ü�� ������ ���� �ּ�(���� ������ ȣ��
Destroy object0000002946FEFCA4     : ��ü ob �Ҹ� - SimpleFuncObj �Լ� ������ ������ SoSimple ��ü ob�� �Ҹ�� ���� �ּ�
Return Object0000002946FEFB64      : �ӽð�ü �ּ� - main �Լ����� ��ȯ�� SoSimple ��ü tempRef�� ������ ���� �ּ�
Destroy object0000002946FEFB64	   : �ӽð�ü �Ҹ� - SoSimple ��ü tempRef�� �Ҹ�� ���� �ּ�
Destroy object0000002946FEFB44     : ��ü obj �Ҹ� - main �Լ����� ������ SoSimple ��ü obj�� �Ҹ�� ���� �ּ�

*/

