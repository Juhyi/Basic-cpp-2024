#include <iostream>
#include <cstring>
#include "11Car.h"
using namespace std;

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