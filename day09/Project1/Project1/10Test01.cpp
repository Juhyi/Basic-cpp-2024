#include <iostream>
using namespace std;

class Myclass {
private:
	int num;				// �ɹ����� num 
public:
	Myclass(int aa = 0) : num(aa)		// ������ ���� num�� aa ����
	{ }
	void print() const					// ����� print ��� �Լ� ����	
	{
		cout << "value: " << num << endl;
	}
	Myclass operator+(const Myclass& ref)	// ������ �����ε� �Է¹��� ��ü�� �ּҰ��� �����Ͽ�
	{
		Myclass pos(num + ref.num);			// ������ aa�� ���� ������ ��ü�� num ���� ���� pos ��ü ����
		return pos;							// ���� ���� ��ü�� ��ȯ��.
	}
	//friend Myclass operator+(const Myclass& ref);
};
/*
Myclass operator+(const Myclass& ref)			
{
	Myclass pos(num + ref.num );
	return pos;												 
}
*/



int main()
{
	Myclass a(10);
	a.print();          //  value : 10 ���
	
	Myclass b(a);
	b.print();          // value : 10 ���

	Myclass c = b;
	c.print();          // value : 10 ��� 

	Myclass d = a + b + c;
	d.print();
	return 0;
}

// ū ��� ���� �� �����ϴ����� ���� �˰� �Ѿ�� => �� ���� ���� 01 ~ 09