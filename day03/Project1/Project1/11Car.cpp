#include <iostream>
#include <cstring>
#include "11Car.h"
using namespace std;

void Car::InitMembers(const char* ID, int fuel)		// ������ �Ǹ� �ȵǱ� ������ const Ű���带 ����
{
	strcpy(gamerID, ID);		// ���޵� ID�� ���ڿ��� �����ؼ� gamerID�� ����
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::showCarState()
{
	cout << "������ ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;
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

void Car::Break()			// �ҽ� ���Ͽ� �����ؼ� ������
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}

	curSpeed = CAR_CONST::BRK_STEP;
}