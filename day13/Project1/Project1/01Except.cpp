#include <iostream>
using namespace std;

void cal(int _n1, int _n2) {
	if (!_n2) throw _n2;
	cout << "���ϱ�: " << _n1 + _n2 << endl;
	cout << "����: " << _n1 - _n2 << endl;
	cout << "���ϱ�: " << _n1 * _n2 << endl;
	cout << "������: " << _n1 / _n2 << endl;
}
int main(int argc, char* argv[])
{
	int n1, n2;
	cout << "���� 2���� �Է��ϼ���: " << endl;
	cin >> n1 >> n2;
	try {						// try : ���ܸ� �߰�
		cal(n1,n2);				// - ���ܹ߻��� ���� �˻��� ������ ����. 
	}
	catch (int exception) {		// catch : ���ܸ� ����
		cout << "0���� ���� �� �����ϴ�." << endl;		// ����ó�� �ڵ��� ����
	}

/* - �����Լ� �� ����ó��
	cout << "���ϱ�: " << n1 + n2 << endl;
	cout << "����: " << n1 - n2 << endl;
	cout << "���ϱ�: " << n1 * n2 << endl;
	try {
		if (!n2) throw n2;						// ���ܸ� ����
		cout << "������: " << n1 / n2 << endl;	// - ����ó�� �ڵ� ����
	}											// try{}catch{} ���̿� �ٸ� ������ ���ԵǸ� �ȵ�. 	
	catch (int exception) {
		cout << "0���� ���� �� �����ϴ�." << endl;
	}
*/
	return 0;
}
// �迭 : �ε����� �� ã��, for��
// �迭 : �˻� <--> ����
// vector : �ڵ����� �޸𸮰� �Ҵ�, template�� ���� vector ����
// - v.front() 
// - v.back() => �� �ڿ��� ����/���� ����, push_back�� �ϸ� �ǳ��� ���� ����, pop_back�� �ϸ� �ǳ� �� ����.
// �߰� ���� ����, ���� ����  