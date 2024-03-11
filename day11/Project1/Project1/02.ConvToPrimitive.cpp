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
	Number& operator=(const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	operator int()    // �� ��ȯ �������� �����ε�
	{
		return num;			// ��ȯ���� ���µ� ��ȯ�� ��.
	}
	void ShowNumber() { cout << num << endl; }
};

int main(void)
{
	Number num1;
	num1 = 30;

	Number num2 = num1 + 20;		// num1 + 20�� ����Ǿ�� �ϴµ� operator+�� ���ǵǾ� ���� ���� => num1�� ����ȭ -> ����ȯ ������ ȣ��
	num2.ShowNumber();
	return 0;
}