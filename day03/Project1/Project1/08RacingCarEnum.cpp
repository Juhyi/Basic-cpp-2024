#include <iostream>
using namespace std;

namespace CAR_CONST			//// CAR_CONST의 이름의 namespace 공간에  구조체 Car이 사용할 상수들 저장
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP =10

	};
}

struct Car				// 구조체 Car
{
	char gamerID[CAR_CONST::ID_LEN];		//ID_LEN을 접근하기 위해 CAR_CONST를 지정, char gameID[20]; 배열
	int fuelGauge;							// :: 접근 연산자	
	int curSpeed;

	void showCarState()
	{
		cout << "소유자 ID: " << gamerID << endl;
		cout << "연료량: " << fuelGauge << "%" << endl;
		cout << "현재속도: " << curSpeed << "km/s" << endl << endl;

	}
	void Accel()
	{
		if (fuelGauge <= 0)
			return;
		else
			fuelGauge -= CAR_CONST::FUEL_STEP;

		if ((curSpeed + CAR_CONST::ACC_STEP) >=CAR_CONST::MAX_SPD)
		{
			curSpeed = CAR_CONST::MAX_SPD;
			return;
		}

		curSpeed += CAR_CONST::ACC_STEP;
	}
	void Break()
	{
		if (curSpeed < CAR_CONST::BRK_STEP)
		{
			curSpeed = 0;
			return;
		}

		curSpeed = CAR_CONST::BRK_STEP;
	}
};

int main(void)
{
	Car run99 = { "run99", 100, 0 };
	run99.Accel();
	run99.Accel();
	run99.showCarState();
	run99.Break();
	run99.showCarState();

	Car run77 = { "run77", 100, 0 };
	run77.Accel();
	run77.Break();
	run77.showCarState();
	return 0;
}


