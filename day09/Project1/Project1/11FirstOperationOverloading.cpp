#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)				// ������ ����� ���ÿ� �ʱ�ȭ, �Ű������� �Է��� ���� ��� �ʱ�ȭ �� ���
	{  }
	void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{  }
	void ShowData() { cout << num3 << ", " << num4 << endl; }

	Second& operator=(const Second& ref)			// ��� : Second Ÿ��, �Լ� : &operator=, �Է� : const Second Ÿ��, ������ ��� ref �ּҰ�
	{												// ���� ������ �����ε� -> ��� �� ��� ���簡 ����Ǳ� ������ ���Կ����� �����ε� ���
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;					// ref.num3�� ��ü���� num3�� ����
		num4 = ref.num4;
		return *this;					// �ڱ��ڽ��� ������ ��ȯ
	}
};

int main(void)
{
	First fsrc(111, 222);
	First fcpy;
	First fcpy = fsrc;  // ������ ���ÿ� �ʱ�ȭ => ����Ʈ ���� ������ ȣ���. 
	Second ssrc(333, 444);
	Second scpy;				// ����Ʈ ���Կ����� ȣ��(����� ��� ����) : ����Ʈ ��������ڿ� �����.
	fcpy = fsrc;				// fcpy.operator=(fsrc)�� �ؼ� -> ����Ʈ�� ���Ե� ���� �����ڰ� ȣ���. (First Ŭ������ ���Կ����ڸ� �����ε� ���� �ʾұ� ����)
	scpy = ssrc;				// scpy.operator=(ssrc)�� �ؼ� -> 23�࿡ ��������� �ۼ��� ���� ������ ȣ��
	cout << endl;
	fcpy.ShowData();			
	scpy.ShowData();

	cout << endl;
	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;		// ���� �����ڴ� �����ʿ��� �������� ����� (���չ��⿡ ����), fsrc�� fob2�� ����, fob2�� fob1�� ���� => ���Կ����� 2�� ȣ��
	sob1 = sob2 = ssrc;     // 45�� ���� , ���Կ����� 2�� ȣ��
	
	cout << endl;
	fob1.ShowData();		
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return 0;
}