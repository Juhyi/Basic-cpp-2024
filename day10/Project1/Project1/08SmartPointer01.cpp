#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)		// ������ 
	{
		cout << "Point ��ü ����" << endl;
	}
	~Point()											// �Ҹ���
	{
		cout << "Point ��ü �Ҹ�" << endl;
	}
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	friend ostream& operator<<(ostream& os, const Point& pos);   // friend�� ����, �����Լ��� ����
};
ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

// ����Ʈ �����ʹ� ��� ��ü, ������ ������ �ϴ� ��ü�� ����
class SmartPtr
{
private:
	Point* posptr;	// ��������� PointŸ���� ������ ��� ������ ����
public:
	SmartPtr(Point* ptr) : posptr(ptr)	// �������� ���ڷ� ���޵Ǵ� �ּҰ��� new���꿡 ���� ���� �Ҵ�� ��ü�� �ּҰ��̶�� ����
	{  }

	Point& operator*() const	// (����Ʈ ������) : ������ó�� �����ϴ� ��ü:  39, 43 ���� �Լ� ���Ǵ� �ʼ���. 
	{							// => �Ҹ��ڸ� ȣ������ �ʾƵ� �ڵ����� delete ������ �����.
		return *posptr;
	}
	Point* operator->() const
	{
		return posptr;			// �����ͷ� ��ȯ
	}
	~SmartPtr()
	{
		cout << "SmartPtr ��ü �Ҹ�" << endl;
		delete posptr;
	}
};

int main(void)
{
	SmartPtr sptr1(new Point(1, 2));		//  new�� ��ü�� �����ϴ� ���ÿ� ����Ʈ������ SmartPtr ��ü�� ����Ű���ϰ� ����
	SmartPtr sptr2(new Point(2, 3));		// => sptr1,2,3�� Point ��ü�� ����Ű�� ������ó�� ����
	SmartPtr sptr3(new Point(4, 5));		
	cout << *sptr1;			// sptr1,2,3�� ������ ó�� *������ ����		
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);		// sptr1,2,3�� ������ó�� ->������ ����.
	sptr2->SetPos(30, 40);
	sptr3->SetPos(50, 60);
	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;
	return 0;
}

// ������ �Ҹ��� ����, Smartptr �Ҹ� -> Point �Ҹ�