#include <iostream>
#include <cstring>
using namespace std;

class Girl;			// class Girl�� ����� �� �ٵ� ���α׷��� ������ �Ʒ��� �������Ƿ� class Girl ���� ���� �ؿ� ������ ������ class gilr ���� ����

class Boy
{
private:
	int height;
	friend class Girl;
public:
	Boy(int len):height(len)
	{ }
	void ShowYourFriendInfo(Girl& frn);			// ����ο� ���Ǻ� �и�
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char* num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn)
{
	cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn) // ::�� ����ؼ� �Ҽ� ������.
{
	cout << "His height: " << frn.height << endl;
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}