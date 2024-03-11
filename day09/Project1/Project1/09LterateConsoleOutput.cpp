#include <iostream>	

namespace mystd
{
	using namespace std;

	class ostream
	{
	public:
		ostream& operator<< (char* str)		// << 연산자 오버로딩
		{
			printf("%s", str);
			return *this;				// 자기 자신의 참조값을 반환해줌.
		}
		ostream& operator<< (char str)
		{
			printf("%c", str);
			return *this;
		}
		ostream& operator<< (int num)
		{
			printf("%d", num);
			return *this;
		}
		ostream& operator<< (double e)
		{
			printf("%g", e);
			return *this;
		}
		ostream& operator<< (ostream& (*fp)(ostream& ostm))
		{
			return fp(*this);
		}
	};

	ostream& endl(ostream& ostm)		// endl 함수는 객체의 참조값을 반환하므로 반환된 값을 재반환하는 형태로 연산자를 오버로딩함.
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;	
	}
	ostream cout;
}

int main(void)
{
	using mystd::cout;
	using mystd::endl;
	cout << 3.14 << endl << 123 << endl;
	return 0;
}