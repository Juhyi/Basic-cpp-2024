#include <iostream>
#include<cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)		// �Է� 2���� ���� ������
	{
		int len = strlen(myname) + 1; // ���ڿ� ���� + 1 : ���ڿ��ΰ� ��Ÿ���� ���� ���ڵ��� �������� NULL ���ڸ� �ٿ���. 
		name = new char[len];
		cout <<"char�� ũ��: "<< sizeof(char) << endl;
		strcpy(name, myname);	// myname�� ���ڿ��� name�� �ٸ� �� 
		age = myage;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~Person()		// �Ҹ��� - �ڵ�ȣ��� main���� ȣ���� �ʿ� ����. ��ü�� 2���̹Ƿ� �Ҹ��� 2�� �߻�.
	{
		delete[]name;		// �޸𸮸� �Ҵ�ް� ���� ��ȯ�ؾ��ϹǷ� �ڵ� ȣ��� �Ҹ��ڿ��� ��ȯ�ϴ� delete ���.
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Jang dong gun", 41);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}