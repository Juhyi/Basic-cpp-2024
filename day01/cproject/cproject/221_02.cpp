#include <iostream>
using namespace std;

int main()
{
	int inKey;
	cout << "�����Է� > ";
	cin >> inKey;

	if (inKey == 3) {	// if(���ǽ�){ ... ���๮}  ���๮�� ������ ��� {} ���� ����
		cout << "����" << endl;
	}
	else if (inKey > 3) {
		cout << "���ڰ� Ů�ϴ�." << endl;
	}
	else if (inKey < 3) {
		cout << "���ڰ� �۽��ϴ�." << endl;
	}
	else cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	return 0;
}
/*
* if ~ else ��
*/