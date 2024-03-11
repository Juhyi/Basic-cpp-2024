#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)		// ������
	{  }
	Point operator+(const Point& pos) const		// +������ �����ε�
	{
		return Point(xpos + pos.xpos, ypos + pos.ypos);	        // �ӽ� ��ü�� ������ ���ÿ� ��ȯ => return �������� ����.
	}
	friend ostream& operator<<(ostream& os, const Point& pos);	// friend ����-> ������������ ����
};

ostream& operator<<(ostream& os, const Point& pos)	 // << ������ �����ε� 
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}	

class Adder		// => �Լ�ó�� �����ϴ� Ŭ���� : ����(Functor) or �Լ� ������Ʈ(Function Object)
{
public:
	int operator()(const int& n1, const int& n2)		// ���� 2���� ���� �޾� ���� �� ��ȯ�ϴ�  () ������ �����ε�
	{
		return n1 + n2;
	}
	double operator()(const double& e1, const double& e2)	// �Ǽ� 2���� ���� �޾� ���� �� ��ȯ�ϴ� () ������ �����ε�
	{
		return e1 + e2;
	}
	Point operator()(const Point& pos1, const Point& pos2)	// ��ü 2���� ���� �� ��ȯ�ϴ� ()������ �����ε�
	{
		return pos1 + pos2;		// ��ü�� ���ϹǷ� ������ �����ε� �ʿ�. 
	}
};

int main(void)
{
	Adder adder;
	cout << adder(1, 3) << endl;				// adder��� �̸��� �Լ��� ȣ���Ͽ� ���� ���, adder�� ��ü������ �Լ�ó�� ����
	cout << adder(1.5, 3.7) << endl;			// 44��� ����
	cout << adder(Point(3, 4), Point(7, 9));	// Point�� �ӽð�ü 2���� �����Ͽ� �Լ��� ���ڷ� ���� => �Լ��� ȣ�⹮������ �ӽð�ü ���� ����
	return 0;
}