#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "New Object: " << this << endl;  // this 객체 자기자신의 주소값, this는 포인터 이므로.  => 객체 obj의 주소
	}
	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "New Copy Object: " << this << endl;  // 객체가 생성되면서 복사 생성자 호출, 객체 ob의 주소 출력
	}
	~SoSimple()
	{
		cout << "Destroy object" << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)		//  SoSimple 타입의 출력을하는 함수 ob가 obj를 복사하여 객체 생성
{
	cout << "Parm ADR: " << &ob << endl;	// 주소 연산자 &를 사용하여 ob의 주소 출력
	return ob;		// 객체 ob를 반환하므로 임시객체 생성됨. 생성 후 출력하지 않으므로 소멸됨. ob도 함수를 벗어나면서 소멸되므로 
					// ob 객체 소멸 후 임시객체도 소멸됨.
}				

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj);
	cout << "Return Object" << &tempRef << endl;
	return 0;

}

/*
New Object: 0000002946FEFB44      : 객체 obj 주소
New Copy Object: 0000002946FEFC44 : 객체 ob 주소
Parm ADR: 0000002946FEFC44		  : 객체 ob 주소
New Copy Object: 0000002946FEFC84 : 임시 객체 주소
Destroy object0000002946FEFC44    : 객체 ob 소멸
Destroy object0000002946FEFC84    : 임시객체 소멸

New Copy Object : 0000002946FEFCA4 : 객체 ob 주소 - main 함수에서 SoSimple 객체 obj가 생성될 때의 주소, 객체 ob 주소
Parm ADR : 0000002946FEFCA4		   : 객체 ob 주소 - SimpleFuncObj 함수 내에서 SoSimple 객체 ob가 생성될 때의 주소(매개변수로 받은 객체의 주소)  
New Copy Object : 0000002946FEFB64 : 임시객체 주소 - SimpleFuncObj 함수 내에서 SoSimple 객체 ob를 복사하여 새로운 객체가 생성될 때의 주소(복사 생성자 호출
Destroy object0000002946FEFCA4     : 객체 ob 소멸 - SimpleFuncObj 함수 내에서 생성된 SoSimple 객체 ob가 소멸될 때의 주소
Return Object0000002946FEFB64      : 임시객체 주소 - main 함수에서 반환된 SoSimple 객체 tempRef가 생성될 때의 주소
Destroy object0000002946FEFB64	   : 임시객체 소멸 - SoSimple 객체 tempRef가 소멸될 때의 주소
Destroy object0000002946FEFB44     : 객체 obj 소멸 - main 함수에서 생성된 SoSimple 객체 obj가 소멸될 때의 주소

*/

