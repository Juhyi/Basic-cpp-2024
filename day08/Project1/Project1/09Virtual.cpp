// date : 2024-03-04
// file : test08_Virtual.cpp
// desc :

#include <iostream>

using namespace std;

class Base {
public:
	Base() {};
	~Base() {};
	virtual void Func1() { cout << "Base::Func1()" << endl; }      // ��ü �߽����� �Ǿ Derived ���� ��µȴ�
	virtual void Func2() { cout << "Base::Func2()" << endl; }
	void Func3() { cout << "Base::Func3()" << endl; }
};

class Derived : public Base {
public:
	void Func1() { cout << "Derived::Func1()" << endl; }
	void Func3() { cout << "Derived::Func3()" << endl; }
	void Func4() { cout << "Derived::Func4()" << endl; }

	Derived() = default;
};

int main()
{
	Base b;            // Base Ÿ���� ��ü����
	Derived d;         // Derived Ÿ���� ��ü����
	Base* pb = new Derived();         // Base Ÿ���� ��ü ������


	pb->Func1();
	pb->Func2();
	pb->Func3();

	cout << endl;
	Derived* pd = &d;      // pd�� Derived d�� �ּҰ� ��
	pd->Func1();         // Derived �Լ����
	pd->Func2();         // Base �Լ����(Derived�� Func2�� ���� ����)
	pd->Func3();         // Derived �Լ����
	pd->Func4();         // Derived �Լ����

	delete pb;      // �������� ��������

	return 0;
}

/*
* ���������Լ� : �Լ��� ��ü�� ���ǵ��� ���� �����Լ� virtual int func1() const =0; // ����
* �߻� Ŭ���� : ���������Լ��� ���� �ҿ����� Ŭ����, ��ü ������ ���� ����. 
* - ������ �̷��� �ʿ��� Ŭ������ �̸� ������. ���ݴ��� ��ü ������ �ʿ����� ���� ����.
*/