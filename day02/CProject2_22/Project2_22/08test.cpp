#include<iostream>
using namespace std;

int global = 100; //��������- ���α׷���ü���� ��밡��
int global1 = 200;

int main()
{
	int val = 100;  // �������� - ����� ���������� ��밡��
	global = 200;	// ���������̹Ƿ� main �Լ� �ȿ��� ����� �� ���� 

	int global1 = 300;	//���������� ������ global1�� �������� �̸��� �����ϰ� ���� => ���������� �����Ѱ� ������. �켱���� : �������� >> ��������



	cout << "�������� global: " << global << endl;
	cout << "��������: " << val << endl;
	
	cout << "�������� global1: " << global1 << endl;

	return 0;
}

void func()
{	
	int val = 0;  // func���� val�� ���� ������ �����Ͽ����Ƿ� func()���� ��밡��.
	global = 10;
	global1 = 10;
	val = 10;  // val�� main �Լ� ���������� ��밡����, main �Լ��� ����� ����� �� ����.
}