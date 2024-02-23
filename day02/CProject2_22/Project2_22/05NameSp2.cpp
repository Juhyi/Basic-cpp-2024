#include <iostream>
using namespace std;

namespace BestComImpl			// 선언
{
	void SimpleFunc(void);		// SimpleFunc은 BestCom의 namespace에 저장된 함수
}

namespace ProgrComImpl
{
	void SimpleFunc(void); // SimpleFunc은 ProgrCom의 namespace에 저장된 함수
}

int main(void)
{
	BestComImpl::SimpleFunc();    // SimpleFunc 이름은 같지만 namespace가 다르므로 다른 함수임.
	ProgrComImpl::SimpleFunc();	// :: => 범위 스코프 // namespace 공간 밖에서 호출, 정의를 할때는 앞에 :: 범위 스코프를 써줘서 어디의 함수인지 알려주기
	return 0;
}

void BestComImpl::SimpleFunc(void)
{
	cout << "BestCom이 정의한 함수" << endl;
}


void ProgrComImpl::SimpleFunc(void)
{
	cout << "ProgrCom이 정의한 함수" << endl;
}