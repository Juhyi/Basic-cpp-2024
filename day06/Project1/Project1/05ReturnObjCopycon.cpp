#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num; // ������ �����ϴ� ��� ����

public:
    // ������
    SoSimple(int n) : num(n)
    { }

    // ���� ������
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "Called SoSimple(const SoSimple& copy)" << endl;
    }

    // ��� ������ ���� ���ϴ� �Լ�
    SoSimple& AddNum(int n)
    {
        num += n; // num = num + n;
        return *this;
    }

    // �����͸� ����ϴ� ��� �Լ�
    void ShowData()
    {
        cout << "Num: " << num << endl;
    }
};

// ��ü�� �Ű������� �޴� �Լ�
SoSimple SimpleFuncObj(SoSimple ob) // ob�� �Լ� �ȿ����� ��� ���� 
{
    cout << "Return Before" << endl;
    return ob;
}

int main(void)
{
    // ��ü ���� �� �ʱ�ȭ
    // SimpleFuncObj �Լ��� ��ü�� �Ű������� �ް�, �� ��ü�� ��ȯ. 
    // ob�� �Լ��� ��� �Ҹ�Ǿ��� ������ AddNum�� �����ϱ� ���� �ӽð�ü �ʿ�
    // �ӽð�ü�� AddNum �Լ��� ȣ���Ͽ� num�� 3�� ���ϰ�,
    // �� ����� ShowData �Լ��� ȣ���Ͽ� num�� ���
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(3).ShowData();

    // ���� ��ü obj�� num ���� ���.
    obj.ShowData();
    return 0;
}
/*
1. SoSimple Ŭ������ ������ �����ϴ� num ��� ������ ������ ����.
2. �����ڸ� ���� num ��� ������ �ʱ�ȭ.
3. ���� �����ڴ� �ٸ� ��ü�� �޾ƿͼ� num ��� ������ ����.
4. AddNum �Լ��� ��� ���� num�� ���� ���ϰ�, ��ü �ڽ��� ����.
5. ShowData �Լ��� ��ü�� num ���� ���.
6. SimpleFuncObj �Լ��� SoSimple ��ü�� �Ű������� �ް�, ���� ��ü�� ��ȯ.
7. main �Լ������� ��ü obj�� �����ϰ�, SimpleFuncObj(obj)�� ȣ���� ��
    ->��ȯ�� ��ü�� AddNum(3)�� ShowData()�� ���������� ȣ��.
8. ���������� obj.ShowData()�� ȣ���Ͽ� ���� ��ü�� num ���� ���.
*/