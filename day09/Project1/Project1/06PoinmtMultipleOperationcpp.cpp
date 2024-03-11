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
	Point operator*(int times)		// ���� ������ �����ε�, Point ��ü�� �������� ���� ����
	{
		Point pos(xpos * times, ypos * times);		// ���� ����ŭ ������ Point ��ü�� �����Ͽ� return����.
		return pos;
	}
};

int main(void)
{
	Point pos(1, 2);	// ��ü ����
	Point cpy;				

	cpy = pos * 3;		// : cpy = pos.operator*(3)�� �������ڷ����� �ٸ� ��ü�� int�� ����. ������ �����ε��� �ƴ϶�� �� �� ����.
	cpy.ShowPosition();

	cpy = pos * 3 * 2;  // pos ��ü�� 3�� ���� ���� �ٽ� 2�� ���ϴ� ����, �� ���� ������� cpy��ü�� �����.
	cpy.ShowPosition();
	return 0;
}