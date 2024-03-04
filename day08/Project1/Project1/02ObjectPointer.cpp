#include <iostream>
using namespace std;

class Person
{
public:
	void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person
{
public:
	void Sleep() { cout << "Student Sleep" << endl; }
	void Study(){ cout << "Study" << endl; }
};

class PartTimeStudent : public Student
{
public:
	void Work() { cout << "Work" << endl; }			// ��� �Լ�, �޽��带 3�� ������ ����
};

int main(void)
{
	Person* ptr1 = new Student();				//	 Student *ptr = new Student : ��Ģ�� ������ Ÿ���� ����ϴ� ��.
	Person* ptr2 = new PartTimeStudent();		// �θ�Ÿ���� ��ü �����ͷ� �ڽ� ��ü�� ����Ű�� �ִ� �� (��� �����̱� ������ ������ ��)
	Student* ptr3 = new PartTimeStudent();		// ������ �ڽ�Ÿ���� ��ü �����ͷ� �θ� ��ü�� ����ų ���� ����.
	ptr1->Sleep();							// �׸��� ** ���� ��ü ������ Ÿ���� ������.  ��ü ������ �̹Ƿ� ���� ������ ���� �����Ѵ�. 
	ptr2->Sleep();
	ptr3->Study();
	ptr3->Sleep();		//	 ���� ��ü�� ������ Ÿ���� �����Ƿ� Student class�� Sleep�� ������. 
	delete ptr1;	delete ptr2;	delete ptr3;
	return 0;
}

// 24�� : Student�� Person�� ����ϹǷ� Person�� ������ ������ Student ���ø� ����Ŵ. 
// ��� ���迡�� ������ �̸��� �Լ� => �������̵� -> ���߿� �ٽ� ����

/*
* �����ε�(Overloading) -��������
* �������̵�(Overrideng) - ������, ��Ӱ��迡�� ���
*/