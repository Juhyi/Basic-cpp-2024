#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc()    // Myfunc() �Լ� virtural�� ����, ���� �ڵ��� Myfunc() �Լ��� virtual�� ������ �ʾƵ� �ڵ����� �����Լ��� ��
	{																					// ������ ���̴°� ����	
		cout << "FirstFunc" << endl;
	}
};

class Second : public First
{
public:
	virtual void MyFunc()			
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second
{
public:
	virtual void MyFunc()
	{
		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	Third* tptr = new Third();			// Third Ÿ���� tptr ������ ������ ����, Third ��ü ���� 
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();				// �Լ��� �����Լ��� ����Ǿ����Ƿ� �ش��Լ� ȣ���, �������� �ڷ����� ����� �ƴ�
	sptr->MyFunc();				// ������ ������ ������ ����Ű�� ��ü�� �����Ͽ� ȣ���� ����� �����Ѵ�. 
	tptr->MyFunc();				
	delete tptr;
	return 0;
}
