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
	* ��ü������ �迭 ���: product[100]
	* string Ŭ���� ��� ����
*/


/*
	* ����ȭ��
	-----��ǰ���� ���α׷�------
	1 ��ǰ�߰� 2 ��ǰ��� 3 ��ǰ�˻� 0 ����
	>

	1 �Ǵ� 2 �Ǵ� 3�� ������ ���
	1 å 2 �ڵ��� 3 ��ǻ��
	���� ����� ��� �ش� ��ǰ�� ������ �Ŀ� �߰�, ��� �Ǵ� �˻��� ����ȴ�
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
		cout << "������ ȣ��" << endl;
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