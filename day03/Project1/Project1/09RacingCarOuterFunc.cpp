#include <iostream>
using namespace std;

namespace CAR_CONST			//CAR_CONST의 이름의 namespace 공간에  구조체 Car이 사용할 상수들 저장
{
	enum 			// 열거형 {}, MyEnum이라는 이름을 가진 enum 자료형
	{
		ID_LEN		= 20,  // 대문자로 상수 선언
		MAX_SPD		= 200,
		FUEL_STEP	= 2,
		ACC_STEP	= 10,
		BRK_STEP	= 10

	};
}

struct Car				// 구조체 Car
{
	//========멤버변수===============
	char gamerID[CAR_CONST::ID_LEN];		//ID_LEN을 접근하기 위해 CAR_CONST를 지정, char gameID[20]; 배열
	int fuelGauge;							// :: 접근 연산자	
	int curSpeed;
	//=======멤버함수==========	// 함수 선언하기
	void showCarState();		// 상태정보 출력
	void Accel();				// 엑셀, 속도 증가
	void Break();				// 브레이크, 속도 감소
	
};

void Car::showCarState()		// Car 구조체 안의 함수 정의
{
	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량: " << fuelGauge << "%" << endl;
	cout << "현재속도: " << curSpeed << "km/s" << endl << endl;


}

void Car::Accel()
{
	if (fuelGauge <= 0)			// fuelGauge: 100, curSpeed: 0
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

void Car::Break()
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
	Car run99 = { "run99", 100, 0 };	//new 키워드 사용 X => 스택영역에 저장
	run99.Accel();		// 98, 10
	run99.showCarState();
	run99.Break();
	run99.showCarState();

}


