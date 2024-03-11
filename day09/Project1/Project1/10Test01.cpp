#include <iostream>
using namespace std;

class Myclass {
private:
	int num;				// 맴버변수 num 
public:
	Myclass(int aa = 0) : num(aa)		// 생성자 선언 num에 aa 복사
	{ }
	void print() const					// 출력할 print 멤버 함수 정의	
	{
		cout << "value: " << num << endl;
	}
	Myclass operator+(const Myclass& ref)	// 연산자 오버로딩 입력받은 객체의 주소값을 복사하여
	{
		Myclass pos(num + ref.num);			// 생성자 aa의 값고 생성된 객체의 num 값을 더한 pos 객체 생성
		return pos;							// 더한 값인 객체를 반환함.
	}
	//friend Myclass operator+(const Myclass& ref);
};
/*
Myclass operator+(const Myclass& ref)			
{
	Myclass pos(num + ref.num );
	return pos;												 
}
*/



int main()
{
	Myclass a(10);
	a.print();          //  value : 10 출력
	
	Myclass b(a);
	b.print();          // value : 10 출력

	Myclass c = b;
	c.print();          // value : 10 출력 

	Myclass d = a + b + c;
	d.print();
	return 0;
}

// 큰 덩어리 별로 왜 정의하는지에 대해 알고 넘어가기 => 이 파일 제외 01 ~ 09