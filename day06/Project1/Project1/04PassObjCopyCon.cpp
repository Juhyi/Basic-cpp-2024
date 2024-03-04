#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n):num(n)
	{
		cout << "Called SoSimple(int n) constructor" << endl;
	
	}
	SoSimple(const SoSimple& copy) : num(copy.num)   // Copy => obj  num => ob
	{
		cout << "Called SoSimple(const SoSimple& copy)" << endl;
	}
	void ShowData()						// ����Լ� --> ��ü ���� �� ��� ����.
	{
		cout << "num: " << num << endl;
	}
};

void SimpleFuncObj(SoSimple ob)    // ��𿡵� �Ҽӵ��� ���� ���� �Լ�. --> ��𿡼��� ������ �ٷ� ���� ����. 
{
	ob.ShowData();				//  SoSimple�� ����Լ� ȣ�� 
}

int main(void)
{
	SoSimple obj(7);
	cout << "�Լ�ȣ�� ��" << endl;
	SimpleFuncObj(obj);
	cout << "�Լ�ȣ�� ��" << endl;
	return 0;
} 