#include <iostream>
using namespace std;

namespace CAR_CONST			//CAR_CONST�� �̸��� namespace ������  ����ü Car�� ����� ����� ����
{
	enum 			// ������ {}, MyEnum�̶�� �̸��� ���� enum �ڷ���
	{
		ID_LEN		= 20,  // �빮�ڷ� ��� ����
		MAX_SPD		= 200,
		FUEL_STEP	= 2,
		ACC_STEP	= 10,
		BRK_STEP	= 10

	};
}

struct Car				// ����ü Car
{
	//========�������===============
	char gamerID[CAR_CONST::ID_LEN];		//ID_LEN�� �����ϱ� ���� CAR_CONST�� ����, char gameID[20]; �迭
	int fuelGauge;							// :: ���� ������	
	int curSpeed;
	//=======����Լ�==========	// �Լ� �����ϱ�
	void showCarState();		// �������� ���
	void Accel();				// ����, �ӵ� ����
	void Break();				// �극��ũ, �ӵ� ����
	
};

void Car::showCarState()		// Car ����ü ���� �Լ� ����
{
	cout << "������ ID: " << gamerID << endl;
	cout << "���ᷮ: " << fuelGauge << "%" << endl;
	cout << "����ӵ�: " << curSpeed << "km/s" << endl << endl;


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
	Car run99 = { "run99", 100, 0 };	//new Ű���� ��� X => ���ÿ����� ����
	run99.Accel();		// 98, 10
	run99.showCarState();
	run99.Break();
	run99.showCarState();

}


