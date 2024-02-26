#include <iostream>
using namespace std;

class MyClass {

};  // 클래스 중괄호 후 ; 



class FruitSeller
{
private:				// 속성 - 매개변수
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:														// 매서드 = 매개함수
	void InitMembers(int price, int num, int money)		// 매개변수 초기화해주는 매서드 ===> 생성자의 기능(객체를 생성하고 초기화)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;		// 판매개수
		numOfApples -= num;					// 남은 사과 개수
		myMoney += money;					// 판매 수익, myMoney = myMoney + money;
		return num;
	 }
	void ShowSalesResult()
	{
		cout << "남은 사과:  " << numOfApples << endl;
		cout << "판매 수익:  " << myMoney << endl;
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
	void BuyApples(FruitSeller& refseller, int money)  // numOfApples의 자료형인 refseller 객체, 참조연산자 refseller와 seller1은 동일한 객체를 가리킴.
	{												   
		numOfApples += refseller.SaleApples(money);	   // FruitBuyer 객체의 함수 내에서 FruitSeller 객체의 함수 SaleApples 호출.
		myMoney -= money; 
	}
	void SowBuyResult()
	{
		cout << "현재 잔액:  " << myMoney << endl;
		cout << "사과 개수:  " << numOfApples << endl;
	}
};

int main(void)
{
	FruitSeller seller1;		// 객체를 생성해서 class 사용. 
	seller1.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);	// buyer라는 객체의 InitMember 사용. 스택영역.
	buyer.BuyApples(seller1, 2000);

	cout << "과일 판매자의 현황:  " << endl;
	seller1.ShowSalesResult();
	cout << "과일 구매자의 현황: " << endl;
	buyer.SowBuyResult();
	return 0;
}