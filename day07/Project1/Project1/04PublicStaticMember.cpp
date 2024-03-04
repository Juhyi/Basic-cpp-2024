#include <iostream>
using namespace std;

class SoSimple
{
public:		                    // 접근 제한자가 public이므로 외부에서 접근 허용 static 멤버변수를 외부에서 사용할 수 있게 해줌
	static int simObjCnt;		// static 멤버변수 선언(클래스 멤버)
public:
	SoSimple()
	{
		simObjCnt++;
	}
};
int SoSimple::simObjCnt = 0;	// static 멤버변수의 초기화 

int main(void)
{
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;	// 6번줄 덕분에 클래스이름으로 static 멤버에 접근 가능
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	cout<<sim1.simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
}