#include <iostream>
using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)				// 생성자 성언과 동시에 초기화, 매개변수에 입력이 없을 경우 초기화 값 사용
	{  }
	void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{  }
	void ShowData() { cout << num3 << ", " << num4 << endl; }

	Second& operator=(const Second& ref)			// 출력 : Second 타입, 함수 : &operator=, 입력 : const Second 타입, 참조자 사용 ref 주소값
	{												// 대입 연산자 오버로딩 -> 멤버 대 멤버 복사가 진행되기 때문에 대입연산자 오버로딩 사용
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;					// ref.num3의 객체값을 num3에 대입
		num4 = ref.num4;
		return *this;					// 자기자신의 포인터 반환
	}
};

int main(void)
{
	First fsrc(111, 222);
	First fcpy;
	First fcpy = fsrc;  // 생성과 동시에 초기화 => 디폴트 복사 생성자 호출됨. 
	Second ssrc(333, 444);
	Second scpy;				// 디폴트 대입연산자 호출(멤버대 멤버 대입) : 디폴트 복사생성자와 비슷함.
	fcpy = fsrc;				// fcpy.operator=(fsrc)로 해석 -> 디폴트로 삽입된 대입 연산자가 호출됨. (First 클래스는 대입연산자를 오버로딩 하지 않았기 때문)
	scpy = ssrc;				// scpy.operator=(ssrc)로 해석 -> 23행에 명시적으로 작성한 대입 연산자 호출
	cout << endl;
	fcpy.ShowData();			
	scpy.ShowData();

	cout << endl;
	First fob1, fob2;
	Second sob1, sob2;
	fob1 = fob2 = fsrc;		// 대입 연산자는 오른쪽에서 왼쪽으로 진행됨 (결합방향에 의함), fsrc를 fob2에 대입, fob2를 fob1에 대입 => 대입연산자 2번 호출
	sob1 = sob2 = ssrc;     // 45줄 동일 , 대입연산자 2번 호출
	
	cout << endl;
	fob1.ShowData();		
	fob2.ShowData();
	sob1.ShowData();
	sob2.ShowData();
	return 0;
}