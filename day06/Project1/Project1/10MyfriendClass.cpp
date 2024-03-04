#include <iostream>
#include <cstring>
using namespace std;

class Girl;			// class Girl이 없어도는 됨 근데 프로그램은 위에서 아래로 내려가므로 class Girl 정의 전에 밑에 나오기 때문에 class gilr 먼저 선언

class Boy
{
private:
	int height;
	friend class Girl;
public:
	Boy(int len):height(len)
	{ }
	void ShowYourFriendInfo(Girl& frn);			// 선언부와 정의부 분리
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

void Girl::ShowYourFriendInfo(Boy& frn) // ::을 사용해서 소속 밝히기.
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