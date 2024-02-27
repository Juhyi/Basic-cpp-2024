#include <iostream>
using namespace std;

class AAA
{
public:
	AAA() {
		cout << "empty object" << endl;
	}
	void ShowYourName() {
		cout << "I'm class AAA" << endl;
	}
};

class BBB
{
private:
	AAA& ref;
	const int& num;

public:
	BBB(AAA& r, const int& n)
		: ref(r), num(n)
	{
		// empty constructor boby
	}
	void ShowYourName()
	{
		ref.ShowYourName();
		cout << "and" << endl;
		cout << "I ref num" << num << endl;

	}
};

int main(void)
{
	AAA obj1;
	BBB obj2(obj1, 20);
	obj2.ShowYourName();
	return 0;
}

/*
* ������(Ŭ���� �̸��� ���� ����Լ��� ����� ����.)
* - ��ü ������ �ڵ����� ȣ��Ǵ� ����Լ�
* - ��� Ŭ������ ����Ʈ �����ڸ� ������ �ִ�.
* - ���� ��������� �����ڸ� �ۼ��ϸ� ����Ʈ �������� ȣ���� �Ұ��ϸ�
* - ����Ʈ �����ڰ� �ʿ��� ���� ��������� �ۼ��Ѵ�.
* - ����������� �ʱ�ȭ�� ����Ѵ�.
* = ��������� �ٸ� �����ڸ� ������ ���, ����Ʈ ������ ȣ���� �Ұ���. �⺻ �����ڸ� ��������� �ۼ��ؾ���.
* 
* 
* 
* 
* ��� �̴ϼȶ�����
* - ��ü �������� ����� ���ÿ� �ʱ�ȭ�� �ʿ��� ��쿡 ����Ѵ�.
* - const ������ ���������� �ʱ�ȭ�� ���.
* - �ʱ�ȭ �����ְ� ���� ������ ����.
* 
*/