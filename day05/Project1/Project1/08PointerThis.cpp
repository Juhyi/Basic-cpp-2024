#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int num) 
	{	
		this->num = num;					// this�� ��ü �ڽ��� �ּҰ��� �ǹ�
		cout << "num=" << num << ", ";
		cout << "address=" << this << ", ";	// This�� ��ü�� �ڱ��ڽ��� ����Ŵ.�Ű����� �̸��� ���� ���� �ʾƵ� �� this�� �������̹Ƿ� -> ���
	}
	void ShowSimpleData()		// ��� �Լ��� ������ �ѹ��� �����ϰ� �� ���Ŀ��� ó���� ������� ������ ��� ������ �����Ѵ�.
	{							
		cout << num << endl;
	}
	SoSimple* GetThisPointer()
	{
		return this;
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();						

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}