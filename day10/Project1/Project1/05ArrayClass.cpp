#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int* arr;     // 포인터 멤버변수 arr 선언
	int arrlen;
public:
	BoundCheckIntArray(int len) :arrlen(len)		// int 1개를 입력으로 갖는 생성자 정의 및 초기화
	{
		cout << "생성자 호출\n" << endl;
		arr = new int[len];							// new 사용하여 arr 주소에 int[len] 대입
	}
	int& operator[] (int idx)				//  []연산자 오버로딩, 출력이 참조형
	{
		cout << "[]연산자함수 호출" << endl;
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			BoundCheckIntArray::~BoundCheckIntArray();  // 프로그램 종료 전 강제적으로 메모리 회수함.
			exit(1);		// 프로그램 종료
		}

		return arr[idx];		// 인덱스에 해당하는 배열의 요소값 반환,But 출력이 참조형 == 반환형이 참조형, 배열 요소의 참조값이 반환됨. 
	}							// 참조값을 이용해서 배열요소에 저장된 값의 참조 뿐만 아니라 변경도 가능. 		
	~BoundCheckIntArray()
	{
		cout << "소멸자 호출" << endl;		// 23행에서 프로그램 종료에 의해 소멸자 호출이 되지 않음. => (22행) 예외처리 필요. 
		delete[]arr;
	}
};

int main(void)
{
	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;
	cout << endl;
	
	for (int i = 0; i < 6; i++)		// arr[5]에서 벗어난 범위의 배열 호출
		cout << arr[i] << endl;

	return 0;
}
