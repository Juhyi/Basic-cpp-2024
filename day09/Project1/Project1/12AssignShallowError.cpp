#include <iostream>
#include <cstring>
using namespace std;

class Person
{
	char* name;
	int age;
public:
	Person(const char* myname, int myage)		// ������ ����
	{
		int len = strlen(myname) + 1;
		name = new char[len];			// new�� ����Ͽ� �������� �����Ҵ�
		strcpy(name, myname);
		age = myage;
	}
	
	Person& Person::operator=(const Person& ref)
	{
		delete []name;		// �޸��� ������ ���� ���� �޸� ���� ��������� ��ġ�� (2)

		int len=strlen(ref.name)+1;
		name= new char[len];
		strcpy(name, ref.name);
		age=ref.age;
		return *this;
	}
	

	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}

	~Person()			// �Ҹ��ڰ� �ѹ� �� ȣ��ǹǷ� ���� �߻�
	{
		delete[]name;							// delete�� �̿��� �޸� ���� 
		cout << "called destructor!" << endl;	// man2�� �Ҹ�ǰ� �����ִ� man1�� ��ü�� �Ҹ��� �����϶� name�� ����Ű�� ���ڿ��� �̹� �Ҹ�Ǿ�����. (man2 ��ü �Ҹ�� �Ҹ�)
	}											// => �̹� �Ҹ�� ���ڿ��� ��Ҹ��ϴ� ������ ����
};

int main(void)
{
	Person man1("Lee dong woo", 29); 
	Person man2("Yoon ji yul", 22);
	man2 = man1;			// man1�� man2�� ���� => ����Ʈ ���Կ����� ȣ�� => man1�� man2�� ������ �ּҰ��� ���� (�ϳ��� ���ڿ��� �� ���� ��ü�� ���ÿ� ����)=> ���� ���縦 ��
							// ���ڿ� "Yoon ji yul"�� ����Ű�� ���ڿ��� �ּ� ���� �Ұ� ��. => ���ڿ��� ���� �Ұ��� (�޸� ���� �߻�) 
	man1.ShowPersonInfo();	// -> ���� ����� �� �������� ������ ��ü �Ҹ�������� �ߺ��Ҹ��ϴ� ������ ����.
	man2.ShowPersonInfo();
	return 0;
}

/*
* ������ ������ �����Ҵ��� �� ���, ����Ʈ ���� �����ڴ� 2���� ������ �߻� ��Ŵ.
* =>�ذ���: 1. ���� ���縦 �����ϵ��� ����
*			  2. �޸� ������ �߻����� �ʵ���, ���� ���翡 �ռ� �޸� ������ ���� ��ġ��.
*/