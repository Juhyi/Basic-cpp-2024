#include <iostream>
using namespace std;

class MyClass {

};  // Ŭ���� �߰�ȣ �� ; 



class FruitSeller
{
private:				// �Ӽ� - �Ű�����
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:														// �ż��� = �Ű��Լ�
	void InitMembers(int price, int num, int money)		// �Ű����� �ʱ�ȭ���ִ� �ż��� ===> �������� ���(��ü�� �����ϰ� �ʱ�ȭ)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;		// �ǸŰ���
		numOfApples -= num;					// ���� ��� ����
		myMoney += money;					// �Ǹ� ����, myMoney = myMoney + money;
		return num;
	 }
	void ShowSalesResult()
	{
		cout << "���� ���:  " << numOfApples << endl;
		cout << "�Ǹ� ����:  " << myMoney << endl;
	}
};

class FruitBuyer
{
	int myMoney;			// private
	int numOfApples;

public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller& refseller, int money)  // numOfApples�� �ڷ����� refseller ��ü, ���������� refseller�� seller1�� ������ ��ü�� ����Ŵ.
	{												   
		numOfApples += refseller.SaleApples(money);	   // FruitBuyer ��ü�� �Լ� ������ FruitSeller ��ü�� �Լ� SaleApples ȣ��.
		myMoney -= money; 
	}
	void SowBuyResult()
	{
		cout << "���� �ܾ�:  " << myMoney << endl;
		cout << "��� ����:  " << numOfApples << endl;
	}
};

int main(void)
{
	FruitSeller seller1;		// ��ü�� �����ؼ� class ���. 
	seller1.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);	// buyer��� ��ü�� InitMember ���. ���ÿ���.
	buyer.BuyApples(seller1, 2000);

	cout << "���� �Ǹ����� ��Ȳ:  " << endl;
	seller1.ShowSalesResult();
	cout << "���� �������� ��Ȳ: " << endl;
	buyer.SowBuyResult();
	return 0;
}