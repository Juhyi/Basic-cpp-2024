#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Human
{
private:
	char name[20];
	char job[20];
	int age;
	int year;
	

public:
	Human(const char* pname, const char* pjob, int aage, int ayear) {
		strcpy_s(name, pname);
		strcpy_s(job, pjob);
		age = aage;
		year = ayear;
	}


	void ShowData()
	{
		cout << name << "  ����: " << job << "�������: "<<year<< " ���� ����: "<<age<< endl;
		
	}
};

int main() {
	Human s1("������","���", 26, 991217);
	s1.ShowData();
	return 0;
}