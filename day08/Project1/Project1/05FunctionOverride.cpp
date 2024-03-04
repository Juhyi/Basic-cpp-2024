#include <iostream>
using namespace std;

class First
{
public:
	void MyFunc()
	{
		cout << "FirstFunc" << endl;
	}
};

class Second : public First    // First�� ��ӵ� Second 
{
public:
	void MyFunc()				// �ڱ��� �޼���� 1�������� ����� �޾� �� 2���� �޼���
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second
{
public:
	void MyFunc()				// �ڱ��� �޼���� 1�������� ����� �޾� ��3���� �޼��� ��� ����
	{
		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	Third* tptr = new Third();		// Third Ÿ���� tptr ������ ������ ����, Third ��ü ����
	Second* sptr = tptr;			// Second Ÿ���� sptr ������ ������ ����
	First* fptr = sptr;				// First Ÿ���� fptr ������ ������ ����


	// ��ü������ Ÿ���� �������� ���� ������ ������.
	// �������̵��� ���� �θ���� �ڽİ����� ������.
	fptr->MyFunc();  // First Ŭ������ �޼���
	sptr->MyFunc();  // Second Ŭ������ �޼���, �θ���� �������� ������ 
	tptr->MyFunc();  // Third Ŭ������ �޼���, �θ���� �������� ������


	sptr->First::MyFunc();  // �θ� Ŭ������ �޼��忡 ���� �ϰ� ������ First:: �� ǥ�����־ �����Ѵ�. 
	
	delete tptr;
	return 0;
}
 // ��ü�����̾���ϴµ� ������ Ÿ���� �������� ���� ������ �����ǹǷ� �����Լ�(��ü������ ����)��� ���� �����. 