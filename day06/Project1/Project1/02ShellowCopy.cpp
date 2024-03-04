#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		cout << "������ ȣ��" << endl;
		int len = strlen(myname) + 1;
		name = new char[len];
	}
	Person(const Person& other) :age(other.age)		// ���� ������
	{	
		cout << "���� ��������� ȣ��" << endl;

		// this->name =other.name;    // ���� ����
		// this->age = other.age; 
		this->name = new char[strlen(other.name + 1)];		// �޸� ���� �Ҵ� �� ���ڿ��� �����ϰ� �Ҵ�� �޸� �ּҰ��� ��� name�� ����. 
		strcpy(name, other.name);							// ��ü ���� ���� ���ڿ��� ���� => �����ͷ� �����ϴ� ������ ��� ������. : ���� ����
		this->age = other.age;			// ����� ��� ����
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()					
	{							
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 20);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}