#include <iostream>
using namespace std;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)		// ���Կ����� �����ε�
	{
		cout << "operator=()" << endl;			// ���ڿ� ���
		num = ref.num;								
		return *this;
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num;
	num = 30;				// ���� �ٸ� �� �ڷ����� �ǿ����ڸ� ������� ���Կ����� ������. 
	num.ShowNumber();		// num = 10 => 1. num = Number(30); -> num.operator =(Number(30)) : �ӽð�ü ���� �� �ӽð�ü�� ������� �ϴ� ���� �����ڸ� ȣ��
	return 0;				// : int�� �����͸� ���ڷ� ���޹޴� Number Ŭ������ ������ ȣ���� ���� Number�� �ӽð�ü�� ������ ��,  
}							//   �� Number ��ü�� ������� ���Կ��� ����
