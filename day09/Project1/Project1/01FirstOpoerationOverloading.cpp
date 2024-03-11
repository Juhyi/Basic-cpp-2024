/*������ �����ε�
- �����ε��� �Լ����� �Ͼ�Ƿ� ������ �����ε��� �����ڸ� �Լ�ȭ�ϰڴٴ� ��. 
- �Լ��� �̸��� �������� => operateor+�� �ٿ��� �����ڸ� �Լ�ȭ���ش�. 
*/

#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)	// ������ ����� �ʱ�ȭ => �Է��� ������ �ʱ�ȭ ���� ����ϰڴ�.
	{  }
	void ShowPosition() const	// �Ӽ� ���� �ٲ�� �ȵǹǷ� ���ȭ const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator+(const Point& ref)    //operator+��� �̸��� �Լ� <�Լ��� ����>����Լ� ���� ���: Point, operator+ : �Լ��̸� (�ȿ� ����): �Է� 
	{									 // ������ Ÿ���� �Է��� 31�࿡�� ����
		Point pos(xpos + ref.xpos, ypos + ref.ypos);	// Point Ÿ���� pos��� ���ο� ��ü ����, �� ���� ��ü�� ���ϴ� ���
		                                                //   => ������ �����ε� : ���� ���� Ÿ���� ��ü�� ������. (�⺻ ������ : �⺻�ڷ����� ����)
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);		// ��ü ����
	Point pos2(10, 20);		// ��ü ����
	Point pos3 = pos1.operator+(pos2);		// ���Կ����ڸ� �̿��ؼ� ��ü ����, �ӽð�ü ���� �� pos3�� ����. 
	Point pos4 = pos2.operator+(pos3);
	pos2.operator+(pos1);

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();

	return 0;
}
