#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;     // ������ ������� arr ����
	int arrlen;
public:
	BoundCheckIntArray(int len) :arrlen(len)		// int 1���� �Է����� ���� ������ ���� �� �ʱ�ȭ
	{
		cout << "������ ȣ��\n" << endl;
		arr = new int[len];							// new ����Ͽ� arr �ּҿ� int[len] ����
	}
	int& operator[] (int idx)				//  []������ �����ε�, ����� ������
	{
		cout << "[]�������Լ� ȣ��" << endl;
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			BoundCheckIntArray::~BoundCheckIntArray();  // ���α׷� ���� �� ���������� �޸� ȸ����.
			exit(1);		// ���α׷� ����
		}

		return arr[idx];		// �ε����� �ش��ϴ� �迭�� ��Ұ� ��ȯ,But ����� ������ == ��ȯ���� ������, �迭 ����� �������� ��ȯ��. 
	}							// �������� �̿��ؼ� �迭��ҿ� ����� ���� ���� �Ӹ� �ƴ϶� ���浵 ����. 		
	~BoundCheckIntArray()
	{
		cout << "�Ҹ��� ȣ��" << endl;		// 23�࿡�� ���α׷� ���ῡ ���� �Ҹ��� ȣ���� ���� ����. => (22��) ����ó�� �ʿ�. 
		delete[]arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	cout << endl;
	
	for (int i = 0; i < 6; i++)		// arr[5]���� ��� ������ �迭 ȣ��
		cout << arr[i] << endl;

	return 0;
}
