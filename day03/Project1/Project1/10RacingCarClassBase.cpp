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
	// �������, �ʵ�, �Ӽ�
private:   // Ŭ���� �� ( Ŭ���� ���� ���ǵ� �Լ�)������ ���� ����
	char gamerID[CAR_CONST::ID_LEN];		
	int fuelGauge;								
	int curSpeed;
	// ����Լ�, �޼���, ���
public:
	void InitMembers(const char * ID, int fuel);	// �ʵ��� �� �ʱ�ȭ ��� �޼���
	void showCarState();			// Ŭ������ ���� .h�� ����Ǿ� ������
	void Accel();				
	void Break();
};

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

int main(void)
{
	Car run99;							// class CarŸ���� ��ü run99 ����
	run99.InitMembers("run99", 100);	// run99 ��ü�� InitMembers() �޼��� ȣ���Ͽ� �ʵ带 �ʱ�ȭ��
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.showCarState();
	run99.Break();
	run99.showCarState();
	return 0;
}
