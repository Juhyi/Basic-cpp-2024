#include <iostream>
using namespace std;

class Person {
private:
	char name[50];  
	int age;
public:
	Person(int myage, const char* myname) {
		cout << "�θ������ ����" << endl;
		age = myage;
		strcpy(name, myname);
	}
	void whatYourName() const {
		cout << "My name is " << name << endl;
	}
	void howOldAreYou() const {
		cout << "I'm " << age << "years old" << endl;
	}
};

class UnivStudent : public Person			// Person Ŭ������ �ִ� ���� ��������. classȮ�� �� �ʵ� 3�� ��� ����
{
private:
	char major[50];
public:
	UnivStudent(const char* myname, int myage, const char* mymajor)
		: Person(myage, myname)	// �θ������ 
	{
		cout << "�ڽĻ����� ����" << endl;
		strcpy(major, mymajor);
	}
	void whoAreYou() const
	{
		whatYourName();
		howOldAreYou();
		cout << "My major is " << major << endl << endl;
	}
};

int main(void)
{	
	UnivStudent obj("������", 26, "IoT");  // 3���� �ʵ带 ����ϹǷ� �Էµ� 3��. 
	obj.whoAreYou(); // 
	return 0; 
}