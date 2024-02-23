#include <iostream>
using namespace std;

namespace CAR_CONST			//// CAR_CONST�� �̸��� namespace ������  ����ü Car�� ����� ����� ����
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

struct Car				// ����ü Car
{
	char gamerID[CAR_CONST::ID_LEN];		//ID_LEN�� �����ϱ� ���� CAR_CONST�� ����, char gameID[20]; �迭
	int fuelGauge;							// :: ���� ������	
	int curSpeed;

	void showCarState()
	{
		cout << "������ ID: " << gamerID << endl;
		cout << "���ᷮ: " << fuelGauge << "%" << endl;
		cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;

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


