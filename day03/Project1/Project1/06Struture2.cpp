/*
*  C++ Ÿ���� ����ü : ����ü ����� ��������� ��� �Լ��� ������.
*/

#include <iostream>

typedef struct human {
	char name[20];			// C++ Ÿ�� ����ü �Ӽ� : ��� ����{name, age, job} 
	int age;
	char job[20];

	void showHuman()		// c++ Ÿ�� ����ü �Ӽ� : ��� �Լ��� ����(���)
	{
		printf("name: %s age: %d job: %s", name, age, job);
	}
}Human;


int main()
{
	int a;
	human h1 = { "ȫ�浿", 50, "����" };		
	h1.showHuman();	// showHuman�� �޼��带 ȣ��

	return 0;

}