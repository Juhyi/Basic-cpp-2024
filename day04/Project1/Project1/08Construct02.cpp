#include <iostream>
using namespace std;

class MyClass {
	int num;

public:
	MyClass() {  // ������ �Լ�
		cout << "������ ȣ��: MyClass()" << endl;
		num = 10;
	}
	MyClass(int anum) {		// ������ �����ε�
		cout << "������ ȣ��: MyClass(int)" << endl;
		num = anum;
	}
	void MyClassInfo() {
		cout << "num:  " << num << endl;
	}
};

int main() {

	MyClass* m = new MyClass();  // new�� ������ ����� ȣ��, ������ ���� m�� �ּҸ� �����Ͽ� ���.
	MyClass m1; // ��ü�� ����, �����ڰ� �ڵ����� ȣ���. ��ü ���� ������� �����ڴ� �ڵ� ȣ�� ��.
	//MyClass m2();  // �޼��� ȣ��, ��ü ������ �ȵ�. 
	m1.MyClassInfo(); 
	MyClass m2(20);  // 20�� �Ű������� ���� �����ڰ� �ֱ� ������ ��� ����
	m2.MyClassInfo();


	return 0;
}

// �����ڸ� ȣ������ ������ defalt �����ڰ� �ڵ����� �������. ����Ʈ ������ => �Է��� ���� �ʴ� ������

