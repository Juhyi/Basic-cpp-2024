#include <iostream>
using namespace std;

class SinivelCap
{
public:
	void Take() const { cout << "�๰�� ��" << endl; }

};

class SneezeCap
{
public:
	void Take() const { cout << "��ä�� ����" << endl; }

};

class SnufleCap
{
public:
	void Take() const { cout << "�ڰ� �ո�" << endl; }

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

// Simple sc(20) : ��ü�� �����ϸ鼭 �ʱ�ȭ, �����ڰ� ���� �Ǿ����Ƿ� ��ü������������ �ڵ����� ȣ��Ǵ� �����ڿ���
//  ������ ������ ������ �߰��� �� ����

// SimpleClass *ptr = new SimpleClass : new => �������� �޸� �Ҵ� ������ ����,  ������ ���� ptr�� ����� ����
// ������ ȣ��� ��ü ����