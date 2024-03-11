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
	friend Point operator+(const Point& pos1, const Point& pos2);	// friend�� ���� : ������ �����ε����� ��� (���к��ϰ� ���� ĸ��ȭ�� ������)
};

Point operator+(const Point& pos1, const Point& pos2)			// �����Լ��� ������ ������ �����ε�
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);  // ������ �����ε� ��ü�κ��� ��ü ���� ��ü�� pos1 + pos2�� ����Ŵ
	return pos;												  // friend�̱� ������ xpos ��� ����. friend�� �������� �ʾҴٸ� getter�� ����Ͽ� xpos ��밡��.
}

int main(void)
{
	Point pos1(3, 4);		   // ��ü ����
	Point pos2(10, 20);		   // ��ü ����
	Point pos3 = pos1 + pos2;  // ������ �����ε��� �����Լ��� ���ǵǾ������Ƿ� ��ü�� ���� �Լ��� ������ �ʿ���� ��ü�� ������ �����ϴ�.
							   // pos1.operator+(pos2); => ����Լ� �϶� ������ �����ε� ȣ�� ����
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}
