#include <iostream>
using namespace std;  // std ���ӽ����̽��� ��� ���� ����ϰڴ�.

int main()
{	
	int inKey;
	cout << "���� �ϳ��� �Է��ϼ��� > ";
	cin >> inKey;

	if (inKey == 3) {	// if(���ǽ�){ ... ���๮}
		cout << "����" << endl;
	}
	if (inKey > 3) {
		cout << "���ڰ� Ů�ϴ�." << endl;
	}
	if (inKey < 3) {
		cout << "���ڰ� �۽��ϴ�." << endl;
	}
	return 0;
}