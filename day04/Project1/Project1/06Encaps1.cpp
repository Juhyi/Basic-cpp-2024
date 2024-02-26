#include <iostream>
using namespace std;

class SinivelCap
{
public:
	void Take() const { cout << "콧물이 남" << endl; } // const를 생략하면 29번줄에서 오류, 상수화 시킨 함수에 호출되기 때문에
													   // const인 함수에 함수를 호출하려면 호출되는 함수도 const화 되어야 한다. 변경될 여지가 있으면 X
};

class SneezeCap
{
public:
	void Take() const { cout << "재채기 멎음" << endl; }

};

class SnufleCap
{
public:
	void Take() const { cout << "코가 뚫림" << endl; }

};

class ColdPatient
{
public:
	void TakeSinivelCap(const SinivelCap& cap) const {    // 참조자 cap을 통해 scap의 값을 변경X 상수화, 함수도 상수화
		cap.Take(); 
	}  
	void TakeSneezeCap(const SneezeCap& cap) const { 
		cap.Take();
	}
	void TakeSnufleCap(const SnufleCap& cap) const {
		cap.Take(); 
	}

};

int main(void)
{
	SinivelCap scap;
	SneezeCap zcap;
	SnufleCap ncap;

	ColdPatient sufferer;
	sufferer.TakeSinivelCap(scap);  // 입력이 객체 
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnufleCap(ncap);
	return 0;

}