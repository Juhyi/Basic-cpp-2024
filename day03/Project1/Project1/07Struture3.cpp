/*
*  C++ Ŭ���� : Ŭ���� ����� ��������� ��� �Լ��� ������.
*/
#include <iostream>

class human {		// ���� ���� ����� ���� �ڷ��� : human class
public:
	char name[20];			// �Ӽ� : ��� ����{name, age, job} 
	int age;
	char job[20];

	void showHuman()		// �Ӽ� : ��� �Լ��� ����(���)
	{
		printf("name: %s age: %d job: %s", name, age, job);
	}
}Human;


int main()
{
	int a;
	// human h1 = { "ȫ�浿", 50, "����" };
	// h1.showHuman();	// showHuman�� �޼��带 ȣ��
	human h1 = { "ȫ�浿", 50, "����" };	//Human Ÿ���� ������ �����ϰ� �ʱ�ȭ�� ��Ų��.
	h1.showHuman();



	return 0;

}