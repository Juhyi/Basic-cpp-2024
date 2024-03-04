#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)	// int�� 1���� �Ű����� �Է��� ���� ������
	{
		cout << "creat obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My name is " << num << endl;
	}
};

int main(void)
{
	Temporary(100); // �̸��� ���� �ӽ� ��ü ���� / ������ ���ÿ� �����, ����� ���� ����			// Temporary obj(100) => ���ݱ��� ����� ��ü ���� ǥ��
	cout << "*************after make!" << endl << endl;

	Temporary(200).ShowTempInfo();	// �ӽ� ��ü �����ϸ鼭 ShowTempInfo() �Լ� ȣ�� �� �ӽð�ü �ٷ� �Ҹ�
	cout << "*************after make!" << endl << endl;

	const Temporary& ref = Temporary(300);		// �ӽ� ��ü�� �����ϴ� ref, const�� ���̸� �ӽð�ü�� ������ �����ϴ�. ��� �� �ӽð�ü �Ҹ� 
	cout << "*************end of main!" << endl << endl;
	return 0;
}