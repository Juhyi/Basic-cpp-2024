// date : 2024-03-08
// file : test07_Homework.cpp
// desc :

/*
	* Parent class
	  class Product : id, price, producer
	* Child class
	  class Book : ISBN, author, title			// 978-89-001-0001-1
	  class Handphone : model, RAM
	  class Computer : model, cpu, RAM
	* 객체포인터 배열 사용: product[100]
	* string 클래스 사용 가능
*/


/*
	* 메인화면
	-----상품관리 프로그램------
	1 상품추가 2 상품출력 3 상품검색 0 종료
	>

	1 또는 2 또는 3을 선택한 경우
	1 책 2 핸드폰 3 컴퓨터
	선택 목록을 띄워 해당 상품을 선택한 후에 추가, 출력 또는 검색이 실행된다
*/

#include <iostream>
#include <cstring>

using namespace std;

class Product
{
private:
	char id[100];
	int price;
	char producer[100];

public:
	Product(const char* iid, int price, const char* producer)
	{
		cout << "생성자 호출" << endl;
	}
};

class Book : public Product
{
private:
	int ISBN;
	char author[100];
	char title[100];
};
class Book : public Product
{
private:
	char model[100];
	int RAM;
};
class Book : public Product
{
	char model[100];
	char cpu[100];
	int RAM;
};

int main()
{
	Product p();


	return 0;
}