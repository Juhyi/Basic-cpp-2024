#include <iostream>
using namespace std;

class AA {
private:
	int a;
	int b;
public:
	AA(int a, int b) {			// int�� �Է��� 2���� �޴� ������
		this->a = a;			// �ڱ� �ڽ��� ��ü���� ����
		this->b = b;
	}
	void AAInfo() {
		cout << a << " " << b << endl;

	}
};
int main()
{	
	AA obj1(10, 20);	// AA���� ��ü ����
	obj1.AAInfo();

	AA obj2(obj1);		// obj1�� �����ϴ� obj2 ��ü ���� => ���� �����ڴ� �ڵ����� ȣ��Ǿ���. <����Ʈ ���� ������>
	obj2.AAInfo();


	return 0;
}