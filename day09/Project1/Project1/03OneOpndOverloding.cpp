#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)		// ������ ����� �ʱ�ȭ => �Է��� ������ �ʱ�ȭ ���� �����.
	{  }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++()			// ++�� ���� ������, ������ �����ε� ����Լ��� ����
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	friend Point& operator--(Point& ref);	// -- �� ���� ������, operator-- friend�� ���� xpos, ypos �Լ� �ۿ��� ��밡��
};

Point& operator--(Point& ref)	// ������ �����ε� ���������� ����, -- & ���������ڷ� ref �ּҰ��� �Է�  ����.
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

int main(void)
{
	Point pos(1, 2);
	++pos;			    // ���� ������, ������ �����ϱ� ���� 1 ���������� ++�� ����Լ��� ���ǵ� ������ �����ε� : pos.operator++()�� �ǹ�
	pos.ShowPosition();   
	--pos;				// --�� ���������� ���ǵ� ������ �����ε� : operator--(pos)�� �ǹ�
	pos.ShowPosition();

	++(++pos);		   		
	pos.ShowPosition();
	--(--pos);			
	pos.ShowPosition();
	return 0;
}