/*
* 메모리 동적할당 - new 연산자 사용
* - 프로그램 실행 중에 메모리를 할당 받는다.
* - 정적은 컴파일 단계에서 메모리 할당.
*/

#include <iostream>
using namespace std;
int main()
{
	cout << "int 크기: "<< sizeof(int) << endl;
	int * pi =  new int;  //new 연산자를 통해서 int 크기의 힙 영역 할당.  <메모리 동적 할당>
						  // 메모리의 주소를 리턴시켜줌. 동일한 타입의 주소를 받기 위해 int 타입, 주소값을 전달 받으므로 포인터 변수 사용
	*pi = 10;	// * :  데이터를 나타냄
	cout << "Pi가 가리키는 곳에 저장된 값: " << *pi << endl;

	delete pi;		      // 동적 할당받은 메모리 공간을 반환한다. *사용한 다음에는 반환을 해주어야 함

	int *pary = new int[10];  // 배열 형태(각 요소는 int)로 힙 영역 할당. pary 포인터 변수로 주소값 전달받음
	for (int i = 0; i < 10; i++) {
		pary[i] = i + 10;			// 배열의 각 방에 원소값을 집어 넣는다. ex) pary[0] = 10	

	}

	for (int i = 0; i < 10; i++) {
		printf("pary[%d] : %d\n", i, pary[i]);
	}

	delete[]pary; // 동적할당한 메모리를 반환한다. (배열의 형태로 반환)

	int arr[10];  // int형 방이 10개인 arr배열 선언 -> 객체 생성X, 스택영역 
	return 0;
}