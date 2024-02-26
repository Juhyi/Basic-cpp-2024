#include "11Car.h"

int main(void)
{
	Car run99;							
	run99.InitMembers("run99", 100);	
	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.showCarState();
	run99.Break();
	run99.showCarState();
	return 0;
}