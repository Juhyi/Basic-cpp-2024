#include <iostream>
using namespace std;

int main(void)
{
	int num = 10;		//�������� ���� �� �ʱ�ȭ
	cout << "num: " << num << endl;

	int *pnum = &num;	// �ּҷ� num������ ����, �ּҿ� �ش��ϴ� ���� ���� ��µ�
	int &rnum = num;	// ������ num������ ����

	// int& ref; (X) => ����� ���ÿ� ������ ������ �ʱ�ȭ(NULL�� �ʱ�ȭ X) ���־���� ����� ����
 
	num = 20;
	cout << endl;
	cout << "num: " << num << endl;
	cout << "*pnum: " << *pnum << endl;		
	cout << "rnum: " << rnum << endl;		

	*pnum = 30;
	cout << endl;
	cout << "num: " << num << endl;
	cout << "*pnum: " << *pnum << endl;
	cout << "rnum: " << rnum << endl;

	rnum = 40;
	cout << endl;
	cout << "num: " << num << endl;
	cout << "*pnum: " << *pnum << endl;
	cout << "rnum: " << rnum << endl;



	return 0;
}