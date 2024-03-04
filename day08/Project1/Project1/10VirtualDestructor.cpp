#include <iostream>
using namespace std;

class First
{
private:
	const char* strOne;
public:
	First(const char* str)
	{
		strOne = new char[strlen(str) + 1];		//new ����Ͽ� �����Ҵ�
	}
	virtual ~First()		// �Ҹ��� ����
	{
		cout << "~First()" << endl;
		delete[]strOne;
	}
};

class Second : public First
{
private:
	const char* strTwo;
public:
	Second(const char* str1, const char* str2) : First(str1)	
	{
		strTwo = new char[strlen(str2) + 1];	// �����Ҵ�
	}
	virtual ~Second()							// virtual �Ҹ��ڸ� �����ϸ� ��ü�� ����Ű�Ƿ� ���������� �Ҹ��ڰ� ����ȴ�.  
	{											// �Ҹ���� : �ڽ� -> �θ�
		cout << "~Second()" << endl;
		delete[]strTwo;
	}
};

int main(void)
{
	// ��Ӱ��迡 �־ ��ü�����ʹ� �����ؾ���. �θ�Ÿ���� ��ü�����ͷ� �ڽ� ��ü�� ����Ű�� ���(������) �����ϱ� ** 
	First* ptr = new Second("simple", "complex");	// First Ÿ���� ptr �����ͺ����� ��ü ����
	delete ptr;		// ��ü �Ҹ��� ptr �����ͷ� ���-> First Ŭ������ �Ҹ��ڸ� ȣ��Ǿ���. �޸� ���� �߻�. 
	return 0;		// ��ü �Ҹ� ���������� delete �����ڿ� ���� ������ ������ �ڷ����� ������� ��� �Ҹ��ڰ� ȣ��Ǿ����.
					// �׷��Ƿ� virtual �Ҹ��ڸ� ����Ͽ� ��� �Ҹ��� ȣ��.
}		