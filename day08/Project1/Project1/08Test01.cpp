/*
* RemoteControl 클래스, SamsungTv 클래스, LgTv 클래스를 설계하고
* remote->on 호출하면 연결된 TV에 따라서
* "삼성 Tv ON"또는 "엘지 TV On"이 출력되도록 프로그램을 완성
*/
#include <iostream>
using namespace std;

class RemoteControl {

public:
	virtual void On() {
		cout << "TV를 켭니다" << endl;
	}
};


class SamsungTv :public RemoteControl {   // RemoteControl 부모 클래스 상속
public:
	void On() const
	{
		cout << "삼성 Tv On" << endl;
	}

};

class LgTv : public SamsungTv {
public:
	void On() const
	{
		cout << "엘지 TV On" << endl;
	}
};


int main(void)
{	
	SamsungTv* remote = new SamsungTv(); // 생성된 객체를 기준으로 접근
	LgTv* remote1 = new LgTv();		

	//RemoteControl* remote = new SamsungTv();
	remote->On();
	//remote = new LgTv();

	remote1->On();
	delete remote;
	return 0;
},.  