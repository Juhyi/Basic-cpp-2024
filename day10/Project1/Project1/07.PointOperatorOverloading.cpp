#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n) : num(n) {  }
	void ShowData() { cout << num << endl; }

	Number* operator->()		// -> ������ �����ε� : ��ü�� �ּ� ���� ��ȯ
	{
		return this;		// ��ü �ڱ� �ڽ��� ��ȯ��
	}

	Number& operator*()			// * ������ �����ε� : ��ü�� �������·� ��ȯ�ϵ��� Number&
	{
		return *this;		// ��ü �ڽ��� ���� ���·� ��ȯ
	}
};

int main(void)
{
	Number num(20);			// ��ü ����
	num.ShowData();			
		
	(*num) = 30;			// (num.operator()) =30�� ����, *������ �����ε��� ��� => (*num) : ��ü num�� ������ ����ó�� ���
	num->ShowData();	    // ->������ �����ε��� ��� => ��ü num�� ������ ����ó�� ���
	(*num).ShowData(); 

	return 0;
}
// ->, * ������ �����ε� => ����Ʈ ������ �����ϱ�  08�� ���Ͽ��� ���