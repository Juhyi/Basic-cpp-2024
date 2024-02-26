#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,  
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

class Car
{
	// 멤버변수, 필드, 속성
private:   // 클래스 내 ( 클래스 내에 정의된 함수)에서만 접근 가능
	char gamerID[CAR_CONST::ID_LEN];		
	int fuelGauge;								
	int curSpeed;
	// 멤버함수, 메서드, 기능
public:
	void InitMembers(const char * ID, int fuel);	// 필드의 값 초기화 담당 메서드
	void showCarState();			// 클래스의 선언 .h에 저장되어 컴파일
	void Accel();				
	void Break();
};

void Car::InitMembers(const char* ID, int fuel)		// 변경이 되면 안되기 때문에 const 키워드를 붙임
{
	strcpy(gamerID, ID);		// 전달된 ID의 문자열을 복사해서 gamerID에 저장
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::showCarState()
{
	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;
}

void Car::Accel()
{
	if (fuelGauge <= 0)			
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;		// fuelGauge:98

	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()			// 소스 파일에 저장해서 컴파일
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}

	curSpeed = CAR_CONST::BRK_STEP;
}

int main(void)
{
	Car run99;							// class Car타입의 객체 run99 생성
	run99.InitMembers("run99", 100);	// run99 객체의 InitMembers() 메서드 호출하여 필드를 초기화함
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.showCarState();
	run99.Break();
	run99.showCarState();
	return 0;
}
