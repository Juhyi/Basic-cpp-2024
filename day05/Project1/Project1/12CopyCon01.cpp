/*
* ���� ������
* - ��ü�� �����Ҷ� ȣ��Ǵ� ������
* - ���� ������ ��ü�� �Է����� �������ϴµ� �̶� ���� ��ü�� ������ �Է����� ���� => �� �ٸ� �޸� ������ �ʿ����� �ʴ�.
*/
#include <iostream>
using namespace std;

class AClass {
public:
	AClass(){
		cout << "����Ʈ ������ ȣ��" << endl;
	}
	AClass(int n){
		cout << "AClass(int n) ������ ȣ��" << endl;
	}
	AClass(const AClass & r) {		// ���� ������, & ������ ���ٸ� ��ü�� �Է����� �޾� ���� �����ڰ� ���� �����Ǿ���. & ������ �޾ƾ���.
									// ������ ���� ����Ǹ� �ȵǱ� ������ const�� �ٿ�����. 
		cout << "AClass(const AClass & r) ������ ȣ��" << endl;

	}


};

void func(int a) {		// n =10�� a=10 �� �ٸ���. ���� ������ &�� ������ �Ͼ�� �� �����ϱ� ���� ����.
	a++;
}


int main(void)
{	
	int n = 10;
	AClass obj1;				// ����Ʈ �����ڷ� ��ü ����
	AClass obj2(10);			// int�� �Է��� 1�� ������ ������ ȣ��
	AClass obj3(obj2);			// ���� ������ ȣ��
	func(n);
	return 0;
}