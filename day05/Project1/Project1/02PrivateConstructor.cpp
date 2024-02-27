#include <iostream>
using namespace std;

class AAA
{
private:
	int num;

private:
	AAA(int n) : num(n) {

	}
public:
	AAA():num(0){}

	~AAA() {};  //�Ҹ��� ~�� ���̸� ��, �����ε� �ȵ�, �Է°� ����
	AAA& CreateInitObj(int n) const
	{
		AAA* ptr = new AAA(n);	// ��ü ����
		return *ptr;
	}
	void ShowNum() const { cout << num << endl; }

};

int main(void)
{
	// AAA a(10);		// private�� �����ڰ� �����������, �ܺο��� ���� ���� => ��ü�� 1���� ������ �� ����. �̱��� ���� -> �޸� ����
						// ��ü�� ������ �����ϴ� ���																			

	AAA base;
	base.ShowNum();

	AAA& obj1 = base.CreateInitObj(3); // obj1,2�� �ٸ���ü  27�� �ٿ��� ��ü 1�� ����, 29���ٿ��� ��ü 1�� ����
	obj1.ShowNum();


	AAA& obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete& obj1;
	delete& obj2;
	return 0;

}