#include <iostream>
#include <cstdio>
using namespace std;
#define _CRT_SECURE_NO_WARNING

class Person
{private:
	char* name;				// ��ü�� �����ؾ� ����Լ�, �ʵ带 ����� �� ����.  								
	int age;				// �������, ����Լ��� ��ü ����.
public:
	Person(const char* pname, int aage) :age(aage)
	{
		name = new char[strlen(pname) + 1];		//new �����ڸ� �̿��ؼ� �������� �޸𸮸� �Ҵ��Ͽ� ����
		strcpy(name, pname); 
		
	}
	Person(const Person& a) :age(a.age)			// ���������� �޸𸮸� �Ҹ��Ҷ� ������ ����Ƿ� ��ü�� ������ �� �Ҹ��� ȣ��
	{
		this->name = new char[strlen(a.name + 1)];		
		strcpy(name, a.name);							
		this->age = a.age; ;
	}
	void personInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	
};



int main()
{
	Person p("������", 26);
	p.personInfo();
	
	Person copyp(p);
	copyp.personInfo();

	return 0;
}