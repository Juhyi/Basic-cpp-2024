#include <iostream>	

namespace mystd				// mystd의 이름을 갖는 namespace 공간 생성
{
	using namespace std;	// 지역공간에서 선언했기 때문에 namespace 영역 안에서만 사용가능.

	class ostream			// ostream 클래스 정의
	{
	public:					
		void operator<< (const char* str)	// << 연산자 오버로딩
		{
			printf("%s", str);		// %s : 문자열
		}
		void operator<< (char str)
		{
			printf("%c", str);		// %c : 문자
		}
		void operator<< (int num)
		{
			printf("%d", num);      // %d : 부호가 있는 10진수
		}
		void operator<< (double e)
		{
			printf("%g", e);		// %g : 값에 따라 %e, %f 선택
		}
		void operator<< (ostream& (*fp)(ostream& ostm))	// 포인터 함수의 참조를 받음.  ostream& ostm의 입력을 받음.
		{
			fp(*this);
		}
	};

	ostream& endl(ostream& ostm)  //endl 함수 정의
	{
		ostm << '\n';		// ostm을 실행하고 개행을 시켜라
		fflush(stdout);
		return ostm;
	}
	ostream cout;
}

int main(void)
{
	using mystd::cout;		// cout 객체
	using mystd::endl;		// endl 객체

	cout << "Simple String";  // 문자열을 입력받고 출력하는 연산자 실행
	// cout << "Simple String" << endl; // 하나씩은 되지만 2개는 안됨. 
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);	// 개행
	return 0;
}