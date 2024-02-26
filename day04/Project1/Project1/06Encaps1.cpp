#include <iostream>
using namespace std;

class SinivelCap
{
public:
	void Take() const { cout << "�๰�� ��" << endl; } // const�� �����ϸ� 29���ٿ��� ����, ���ȭ ��Ų �Լ��� ȣ��Ǳ� ������
													   // const�� �Լ��� �Լ��� ȣ���Ϸ��� ȣ��Ǵ� �Լ��� constȭ �Ǿ�� �Ѵ�. ����� ������ ������ X
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

class ColdPatient
{
public:
	void TakeSinivelCap(const SinivelCap& cap) const {    // ������ cap�� ���� scap�� ���� ����X ���ȭ, �Լ��� ���ȭ
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
	sufferer.TakeSinivelCap(scap);  // �Է��� ��ü 
	sufferer.TakeSneezeCap(zcap);
	sufferer.TakeSnufleCap(ncap);
	return 0;

}