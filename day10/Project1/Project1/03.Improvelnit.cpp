#include <iostream>
using namespace std;

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n)		// 생성자 선언 및 초기화, 생성자 오버로딩/ 정수 1개를 입력으로 갖는 생성자
	{
		cout << "AAA(int n=0)" << endl;
	}
	AAA(const AAA& ref) : num(ref.num)		// 객체 1개를 입력으로 갖는 생성자
	{
		cout << "AAA(const AAA & ref)" << endl;
	}
	AAA& operator=(const AAA& ref)			// 출력 : AAA 타입, 함수 : &operator=, 입력 : const AAA 타입, 참조자 사용 ref 주소값
	{										// 대입 연산자 오버로딩 -> 멤버 대 멤버 복사가 진행되기 때문에 대입연산자 오버로딩 사용		
	
		num = ref.num;
		cout << "operator=(const AAA &ref)" << endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;				// AAA 타입의 객체 
public:
	BBB(const AAA& ref)		//이니셜라이저 이용해서 멤버 초기화=>콜론 초기화, AAA& ref에서 객체 생성 연산자가 호출됨.
		: mem(ref)
	{  }
};

class CCC
{
private:
	AAA mem;		// AAA 타입의 객체 
public:
	CCC(const AAA& ref)	   // 대입연산자을 이용해서 멤버 초기화, 생성자 호출
	{
		mem = ref;		   // 대입연산자 호출
	}
};

int main(void)
{
	AAA obj1(12);								// 객체 생성
	cout << "*********************" << endl;
	BBB obj2(obj1);								// obj1을 obj2에 복사 : AAA(const AAA& ref) 생성자가 호출됨.
	cout << "*********************" << endl;
	CCC obj3(obj1);								// obj1을 obj3에 복사 : AAA& operator=(const AAA& ref) 생성자가 호출됨. 대입연산자 오버로딩 과정에서 생성자
	return 0;									// 호출된 후 대입연산자 오버로딩이 호출됨. 			
}

// 멤버 이니셜라이저를 이용해서 멤버를 초기화하는게 속도가 더 빠름.

/*
// 배열이름은 arr은 배열의 시작주소이다. 
int arr[3];   // 배열선언부에서 배열 인덱스에 있는 숫자는 방의 크기, arr[0], arr[1], arr[2] 이외의 방들은 할당받은 배열의 크기를 벗어난다. 
arr[2];       // 코드 실행에서 배열 인덱스에 있는 숫자는 방 번호

arr[0] =10 ;  // 0번 방, 첫번째 방의 데이터
*(arr + 0) = 10    // 배열의 시작주소 + 0 => 첫번째 방/ *() =>()의 데이터에 10을 대입해라.
// []=> *와 동일한 기능.
* (arr + 1) = 20 == arr[1] = 20;  // 1번방에다 20을 대입해라.

arr의 주소가 0x0011 이라면 다음방, 1번방의 주소는  0x0015이다.
int* p;		  // 포인터를 나타내는 기호 *
*p;			  // 포인터가 가리키는 데이터의 값 * 
*/ 