#include <iostream>
#include <string.h>

using namespace std;

class Simple
{
	public:
		Simple()	// ������(Ŭ�����̸��� ���� �ż���)
		{
			cout << "I'm simple constructor!" << endl;
		}
};


/*
1. Simple Ŭ������ �Ҹ��ڰ� �߰�.
 => �������� �Ҵ�� �޸𸮸� �����ϱ� ���� �Ҹ��ڿ��� delete ������ ����
 */

int main(void) {

    cout << " case 1: ";
    Simple* sp1 = new Simple; // �������� new �����ڸ� ���� Simple ��ü ����
    //Aaa *ap = new Aaa;


    cout << " case 2: ";
    Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1); // malloc �Լ��� �� ������ �޸� �Ҵ�
    // ���� ������ �ִ� ������ ���� sp2�� �����ؼ� heap ������ �ּҰ� ����

    cout << endl << "end of main !" << endl;
    delete sp1; // �������� �Ҵ�� ��ü ���� , ��ü�� ��ȯ
    free(sp2); // malloc���� �Ҵ�� �޸� ����
    // Simple�� ���� ���� ��ü�� �ȳ���, �ٵ� char�� ���� �ִ� Ÿ���̶� ����
    return 0;
}

/*
1. delete ������ �������� �Ҵ�� ��ü�� �����ϰ� �ش� ��ü�� �Ҹ��ڸ� ȣ��.
2. malloc �Լ��� �Ҵ�� �޸𸮿� ���� -> free �Լ��� ȣ���Ͽ� �޸𸮸� �����ؾ� ��.
*/

// malloc, delete ���� ������ �˰� �Ѿ��, ������, �����Ҵ翡 ���� �����ϰ� ���� �ٽ� ���� 

/*
*  => �Ҹ��ڸ� �߰��� ������ �������� �Ҵ�� ��ü�� �� �̻� �ʿ����� ���� �� �ش� ��ü�� �޸𸮸� �����ϱ� ���ؼ�.

C++���� ��ü�� �������� �Ҵ�Ǹ� �޸𸮴� ���α׷��� ��(heap)�� �Ҵ�. 
-> ��ü�� �� �̻� �ʿ����� ���� ������ �ش� �޸𸮸� ����. 
-> �Ҹ��ڴ� ��ü�� �Ҹ�� �� ȣ��Ǵ� Ư���� ��� �Լ��μ�, �ַ� ��ü�� �� �̻� �ʿ����� ���� �� �Ҵ�� ���ҽ��� �����ϱ� ���� ����.

�� �ڵ忡���� Simple Ŭ������ �������� �Ҵ�� �� ���� ��ü�� ����. 
-> �̵� ��ü�� ���� new �����ڿ� malloc �Լ��� ����Ͽ� �������� �Ҵ�. 
-> �׷��� �̵� ��ü�� �� �̻� �ʿ����� ���� ������ �ش� �޸𸮸� ����. 
-> �Ҹ��ڸ� �߰������ν� ��ü�� �Ҹ�� �� �Ҵ�� �޸𸮸� ��������. 
-> �̴� ���α׷��� �޸𸮸� ȿ�������� �����ϰ� �޸� ������ �����ϴ� �� ������ ��.
*/