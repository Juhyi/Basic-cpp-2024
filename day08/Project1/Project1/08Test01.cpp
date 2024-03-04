/*
* RemoteControl Ŭ����, SamsungTv Ŭ����, LgTv Ŭ������ �����ϰ�
* remote->on ȣ���ϸ� ����� TV�� ����
* "�Ｚ Tv ON"�Ǵ� "���� TV On"�� ��µǵ��� ���α׷��� �ϼ�
*/
#include <iostream>
using namespace std;

class RemoteControl {

public:
	virtual void On() {
		cout << "TV�� �մϴ�" << endl;
	}
};


class SamsungTv :public RemoteControl {   // RemoteControl �θ� Ŭ���� ���
public:
	void On() const
	{
		cout << "�Ｚ Tv On" << endl;
	}

};

class LgTv : public SamsungTv {
public:
	void On() const
	{
		cout << "���� TV On" << endl;
	}
};


int main(void)
{	
	SamsungTv* remote = new SamsungTv(); // ������ ��ü�� �������� ����
	LgTv* remote1 = new LgTv();		

	//RemoteControl* remote = new SamsungTv();
	remote->On();
	//remote = new LgTv();

	remote1->On();
	delete remote;
	return 0;
},.  