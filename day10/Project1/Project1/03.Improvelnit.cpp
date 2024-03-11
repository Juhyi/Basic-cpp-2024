#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n)		// ������ ���� �� �ʱ�ȭ, ������ �����ε�/ ���� 1���� �Է����� ���� ������
	{
		cout << "AAA(int n=0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)		// ��ü 1���� �Է����� ���� ������
	{
		cout << "AAA(const AAA & ref)" << endl;
	}
	AAA& operator=(const AAA& ref)			// ��� : AAA Ÿ��, �Լ� : &operator=, �Է� : const AAA Ÿ��, ������ ��� ref �ּҰ�
	{										// ���� ������ �����ε� -> ��� �� ��� ���簡 ����Ǳ� ������ ���Կ����� �����ε� ���		
	
		num = ref.num;
		cout << "operator=(const AAA &ref)" << endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;				// AAA Ÿ���� ��ü 
public:
	BBB(const AAA& ref)		//�̴ϼȶ����� �̿��ؼ� ��� �ʱ�ȭ=>�ݷ� �ʱ�ȭ, AAA& ref���� ��ü ���� �����ڰ� ȣ���.
		: mem(ref)
	{  }
};

class CCC
{
private:
	AAA mem;		// AAA Ÿ���� ��ü 
public:
	CCC(const AAA& ref)	   // ���Կ������� �̿��ؼ� ��� �ʱ�ȭ, ������ ȣ��
	{
		mem = ref;		   // ���Կ����� ȣ��
	}
};

int main(void)
{
	AAA obj1(12);								// ��ü ����
	cout << "*********************" << endl;
	BBB obj2(obj1);								// obj1�� obj2�� ���� : AAA(const AAA& ref) �����ڰ� ȣ���.
	cout << "*********************" << endl;
	CCC obj3(obj1);								// obj1�� obj3�� ���� : AAA& operator=(const AAA& ref) �����ڰ� ȣ���. ���Կ����� �����ε� �������� ������
	return 0;									// ȣ��� �� ���Կ����� �����ε��� ȣ���. 			
}

// ��� �̴ϼȶ������� �̿��ؼ� ����� �ʱ�ȭ�ϴ°� �ӵ��� �� ����.

/*
// �迭�̸��� arr�� �迭�� �����ּ��̴�. 
int arr[3];   // �迭����ο��� �迭 �ε����� �ִ� ���ڴ� ���� ũ��, arr[0], arr[1], arr[2] �̿��� ����� �Ҵ���� �迭�� ũ�⸦ �����. 
arr[2];       // �ڵ� ���࿡�� �迭 �ε����� �ִ� ���ڴ� �� ��ȣ

arr[0] =10 ;  // 0�� ��, ù��° ���� ������
*(arr + 0) = 10    // �迭�� �����ּ� + 0 => ù��° ��/ *() =>()�� �����Ϳ� 10�� �����ض�.
// []=> *�� ������ ���.
* (arr + 1) = 20 == arr[1] = 20;  // 1���濡�� 20�� �����ض�.

arr�� �ּҰ� 0x0011 �̶�� ������, 1������ �ּҴ�  0x0015�̴�.
int* p;		  // �����͸� ��Ÿ���� ��ȣ *
*p;			  // �����Ͱ� ����Ű�� �������� �� * 
*/ 