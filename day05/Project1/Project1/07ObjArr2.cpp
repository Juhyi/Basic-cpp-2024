/*
* ��ü �迭
*/
# define _CRT_SECURE_NO_WARNINGS
# include <iostream>
using namespace std;

class Human {
private:
	char name[30];
	int age;

public:
	Human(const char* pname, int aage)
	{
		cout << "������ ȣ��" << endl;
		strcpy(name, pname);
		age = aage;
	}
	void HumanInfo() {
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;

	}

	~Human()
	{
		
		cout << "�Ҹ��� ȣ��" << endl;
	}


};


int main() 
{
	Human h[3] = { Human("ȫ�浿", 50), Human("������", 26), Human("�����", 29) };		// ��ü �迭

	for (int i = 0; i < 3; i++) {

		h[i].HumanInfo();				

	}

	Human* h1 = new Human("�ٺ�", 50);  // �� ������ ��ü ����, ������ ���� h1���� �ּҰ� ���޹���
	h1->HumanInfo();					// h1�� ������ ��ü �̹Ƿ� ���� ���� -> �� ���� �����Ϳ� ���� 
										// ��ü�����Ͱ� ����Ű�� ����� ����
	Human h2("��û��", 20);
	h2.HumanInfo();                     // �Ϲ� ��ü �̹Ƿ� ���� ���� . �� ���� �����Ϳ� ����, �����Ͱ� �ƴ� �������� ��ü�� ����
	return 0;
}