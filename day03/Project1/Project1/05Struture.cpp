/*
*  C Ÿ���� ����ü : ����� ��� ������ ����
*/
#include <stdio.h>

typedef struct human {			// human ����ü ���� <struct ����ü �̸� {������� ����};>
								// ���� ���� ����� ���� �ڷ��� : human ����ü	
	char name[20];		// CŸ�� ����ü �Ӽ� : ��� ����{name, age, job} ���� ����
	int age;
	char job[20];
}Human;				// ������ human ����ü�� Human���� ����Ѵ�.

void showHuman(Human h)
{
	printf("name: %s age: %d job: %s\n", h.name, h.age, h.job); // %s : ���Ĺ��� (s => ����, d => ���� )
}


int main()
{
	int a;
	human h1 = { "ȫ�浿", 50, "����" };		//Human Ÿ���� ������ �����ϰ� �ʱ�ȭ�� ��Ų��.
	showHuman(h1);

	return 0;

}