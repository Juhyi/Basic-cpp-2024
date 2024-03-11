#include <iostream>
using namespace std;

template <typename T> 
T Add(T num1, T num2)
{
	return num1 + num2;
}




int main(void)
{
	cout<< Add<int>(15, 20)			<<endl;  // <int> : T를 int로 해서 만들어진 Add함수를 호출. 
	cout<< Add<double>(2.9, 3.7)	<<endl;  // 함수는 자료형 당 하나씩만 만들어짐.
	cout<< Add<int>(3.2, 3.2)		<<endl;
	cout<< Add<double>(3.14, 2.75)	<<endl;
	return 0;
}

int main(void)
{
	cout << Add(15, 20) << endl;
	cout << Add(2.9, 3.7) << endl;
	cout << Add(3.2, 3.2) << endl;
	cout << Add(3.14, 2.75) << endl;
	return 0;
}
