#include <iostream>

int main()
{
	const int num = 10;		// ����� �����Ҷ��� ����� ���ÿ� �ʱ�ȭ �ʼ�
	//int& ref = num;			// ���ȭ �Ǿ��ִٸ� � �� ���ص� ���� ������ �� ����.

	const int& ref = 30;		// �ӽ÷� ������ ������ ���ȭ�Ͽ� �����ڰ� �����ϵ��� �� �� ����.
								// ���ȭ�� ������ �����ϴ� ����

	return 0;
}

// int a = 10;
// int b = 20;
// int res = a + b;

// �������� -> cpu(����)�� ����ϴ� �޸�, ����ӵ� ����, ���
// heap ��������  malloc()��ſ� c++���� new�� �޸� �Ҵ�, free()��ſ� delet�� ��ȯ.