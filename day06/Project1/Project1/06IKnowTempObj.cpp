#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)	// int형 1개의 매개변수 입력을 갖는 생성자
	{
		cout << "creat obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My name is " << num << endl;
	}
};

int main(void)
{
	Temporary(100); // 이름이 없는 임시 객체 생성 / 생성과 동시에 사라짐, 사용이 없기 때문			// Temporary obj(100) => 지금까지 사용한 객체 생성 표현
	cout << "*************after make!" << endl << endl;

	Temporary(200).ShowTempInfo();	// 임시 객체 생성하면서 ShowTempInfo() 함수 호출 후 임시객체 바로 소멸
	cout << "*************after make!" << endl << endl;

	const Temporary& ref = Temporary(300);		// 임시 객체를 참조하는 ref, const를 붙이면 임시객체도 참조가 가능하다. 출력 후 임시객체 소멸 
	cout << "*************end of main!" << endl << endl;
	return 0;
}