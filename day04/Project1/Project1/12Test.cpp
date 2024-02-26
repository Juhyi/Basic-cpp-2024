#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class StudentClass
{
private:
	const int ID;			// �й��� ���ȭ => ��ü�� �����Ǳ� ���� �ʱ�ȭ�� ���Ѿߵ�.  
	char Name[20];
	char Major[20];
	int  Age;

public:
	StudentClass(int id, const char *pname, const char *pmajor, int age) : ID(id){ 
									  // <��� �̴ϼȶ�����> : ��ü ������ �ʱ�ȭ�����ʴ� ������� �ʱ�ȭ�Ҷ� ���.
									  // => ��ü ������ ������� �̸� �ʱ�ȭ�� �Ǵ� ������� �ʱ�ȭ
									  // <���ڿ� �Է¹ޱ�>
									  // ���ڿ��� ����� ���ÿ� �ʱ�ȭ���� �ʾ��� �� : �����ͷ� �迭�� ����
									  // ���ڿ��� ����Ǹ� �ȵǹǷ� const // strcpy()�� ���Ͽ� �ʱ�ȭ �Ѵ�.
		//ID = id;					  		
		strcpy_s(Name, pname);        // strcpy => string copy�� ���Ӹ�, 
									  //�Լ��� � ����(�޸�) or ���ڿ� ����� ���� �Ǿ��ִ� ���ڿ��� �ٸ� ����(�޸�) ������ �� ���
									  // strcpy_s => strcpy�Լ��� ������ �����ϱ� ���ؼ� ������� �Լ�
		strcpy_s(Major, pmajor);	  // strcpy(str1, str2) => str2�� str1�� �����Ѵ�.
		Age = age;					  // ���ڿ��� �ּ��̹Ƿ� ������ ������ �־ ����Ѵ�. ���ڿ��� ù��° ���� �ּҰ� ����ȴ�. 	
	}
	


	void ShowData()
	{
		cout << "�й�: " << ID << endl;
		cout << "�̸�: " << Name << endl;
		cout << "����: " << Major << endl;
		cout << "����: " << Age << endl;
	}
};



int main(void)
{
	StudentClass student1(001, "������", "Iot", 26);	// ��ü�� �����ϸ� �����ڸ� ȣ���ؾ���. �����ڸ� ȣ���ϴ� �ڵ�
	student1.ShowData();								// ���ڿ��� ����� �ּҸ� ��� *pname
	return 0;
}



