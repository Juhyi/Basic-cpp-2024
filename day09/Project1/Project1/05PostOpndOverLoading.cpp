#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point& operator++()		// ����Լ��� ���ǵ� ������ �����ε�, �������� - �����ϰ� ���� ���� �� a = ++1 => �����Ѱ� ���� a = 2
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}
	const Point operator++(int)		// ����Լ��� ���ǵ� ������ �����ε�, �������� - ���� �ְ� ����, int�� ���������� ǥ���ϱ� ���� ���� �� �ǹ� ����. 
	{  // 1. ������ ��ü�� �����Ͽ� ������ �Ӽ����� ������Ŵ																		//  a = i++, i���� a�� ������ �� i + 1 ����.		
		const Point retobj(xpos, ypos);   // const Point retobj(*this);, ���� ������Ű�� ���� ��ȯ�� �� ���纻�� ����, ���纻�� ���� ������� �ʵ��� const
		// 2. ���� ��ü�� �Ӽ����� 1�� ������Ų��. 
		xpos += 1;
		ypos += 1;
		return retobj;			// 3. ����� ���� �����ϱ� ������ ���纻�� ��ȯ => ���������� ȿ��
	}
	friend Point& operator--(Point& ref);				// friend�� ����
	friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref)		// �����Լ��� ����� ������ �����ε�, ��������
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

const Point operator--(Point& ref, int)		// �����Լ��� ����� ������ �����ε�, �Ű������� ���� int�� �߰�-> ��������
{
	const Point retobj(ref);		// return�Ǵ� retobj�� constȭ retobj�� �Լ��� ����� �Ҹ�, �ӽð�ü�� �������.
	ref.xpos -= 1;					// �ӽð�ü�� const�̱� ���ؼ� �Լ��� ����� constȭ ����.
									// const �Լ� �������� const �Լ��� ȣ�⸸ ����ϵ��� ����.	
	ref.ypos -= 1;					// const�� Ÿ���� ����, const ������ �����ε��� ����.
	return retobj;
}

int main(void)
{
	Point pos(3, 5);
	Point cpy;
	cpy = pos--;			// ���� ���Ҹ� ��Ÿ��. --�� ���������� ���ǵ� ������ �����ε� : operator--(pos)�� �ǹ� 
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++;			// ���� ������ ��Ÿ��. ++�� ����Լ��� ���ǵ� ������ �����ε� : pos.operator++()�� �ǹ�
	cpy.ShowPosition();
	pos.ShowPosition();
	return 0;
}

Point pos(3, 5);
//(pos++)++;  // ���� ���������� �ӽ� ��ü�� ���޹���. �ӽ� ��ü�� const�̹Ƿ� ������ų �� ���� ������ ������ ����. 
//++(++pos);  // ���� ������ �ڱ� ���� ��ȯ�ϰ� const�� �ƴϹǷ� ������ ������ ���� ����. 