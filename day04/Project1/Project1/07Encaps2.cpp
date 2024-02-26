#include <iostream>
using namespace std;

class SinivelCap
{
public:
	void Take() const { cout << "콧물이 남" << endl; }

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

class CONTAC600
{
private:
	SinivelCap sin;
	SneezeCap sne;
	SnufleCap snu;
public:
	void Take() const {
		sin.Take();
		sne.Take();
		snu.Take();

	}
};


class ColdPatient
{
public:
	void TakeCONTAC600(const CONTAC600& cap) const {    
		cap.Take();
	}
	
};

int main() {
	CONTAC600 cap;
	ColdPatient sufferer;
	sufferer.TakeCONTAC600(cap);
	return 0;
}

// Simple sc(20) : 객체를 생성하면서 초기화, 생성자가 정의 되었으므로 객체생성과정에서 자동으로 호출되는 생성자에게
//  전달할 인자의 정보를 추가할 수 있음

// SimpleClass *ptr = new SimpleClass : new => 힙영역에 메모리 할당 생성자 생성,  포인터 변수 ptr을 사용해 접근
// 생성자 호출로 객체 생성