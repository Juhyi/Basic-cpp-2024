#include <iostream>	

namespace mystd				// mystd�� �̸��� ���� namespace ���� ����
{
	using namespace std;	// ������������ �����߱� ������ namespace ���� �ȿ����� ��밡��.

	class ostream			// ostream Ŭ���� ����
	{
	public:					
		void operator<< (const char* str)	// << ������ �����ε�
		{
			printf("%s", str);		// %s : ���ڿ�
		}
		void operator<< (char str)
		{
			printf("%c", str);		// %c : ����
		}
		void operator<< (int num)
		{
			printf("%d", num);      // %d : ��ȣ�� �ִ� 10����
		}
		void operator<< (double e)
		{
			printf("%g", e);		// %g : ���� ���� %e, %f ����
		}
		void operator<< (ostream& (*fp)(ostream& ostm))	// ������ �Լ��� ������ ����.  ostream& ostm�� �Է��� ����.
		{
			fp(*this);
		}
	};

	ostream& endl(ostream& ostm)  //endl �Լ� ����
	{
		ostm << '\n';		// ostm�� �����ϰ� ������ ���Ѷ�
		fflush(stdout);
		return ostm;
	}
	ostream cout;
}

int main(void)
{
	using mystd::cout;		// cout ��ü
	using mystd::endl;		// endl ��ü

	cout << "Simple String";  // ���ڿ��� �Է¹ް� ����ϴ� ������ ����
	// cout << "Simple String" << endl; // �ϳ����� ������ 2���� �ȵ�. 
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);	// ����
	return 0;
}