#include <iostream>
using namespace std;

class First
{
public:
	void FirstFunc()
	{
		cout << "FirstFunc()" << endl;
	}
	virtual void SimpleFunc()				// �����Լ� 
	{
		cout << "First's SimpleFunc()" << endl;
	}
};

class Second : public First		//  First Ŭ������ ���
{
public:
	void SecondFunc()
	{
		cout << "SecondFunc()" << endl;
	}
	virtual void SimpleFunc()			// �����Լ�
	{
		cout << "Second's SimpleFunc()" << endl;
	}
};

class Third : public Second
{
public:
	void ThirdFunc()
	{
		cout << "ThirdFunc()" << endl;
	}
	virtual void SimpleFunc()			// �����Լ�
	{
		cout << "Third's SimpleFunc()" << endl;
	}
};

int main(void)
{
	Third obj;				// Third Ÿ���� obj ��ü����, �������̺�
	obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();

	cout << endl;
	Second& sref = obj;		// obj�� Second�� ����ϴ� Third ��ü => Second�� �����ڷ� ���� ����.
	sref.FirstFunc();
	sref.SecondFunc();
	sref.SimpleFunc();     // Third Ŭ������ ���ǵ� SimpleFunc �����Լ� ȣ���
	
	cout << endl;
	First& fref = obj;		
	fref.FirstFunc();
	fref.SimpleFunc();		// Third Ŭ������ ���ǵ� SimpleFunc �����Լ� ȣ���
	return 0;	
}