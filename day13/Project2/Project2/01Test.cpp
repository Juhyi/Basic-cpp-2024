#include <iostream>
using namespace std;

int main() {
    char ary[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int length = sizeof(ary) / sizeof(ary[0]); // �迭�� ���� ��� : �迭�� ��ü ũ�⸦ �ڷ��� ũ��� ������ => �迭�� ����

    int i = 0;

    cout << "�ٲٱ� �� �迭: ";
    while (i < length) {
        cout << ary[i]; // �迭 ��Ҹ� �ϳ��� ���
        i++;
    }
    cout << endl;
    /*
    i = 0;
    while (i < length / 2) {             // �迭�� �������� ����� ���� ��Ұ��� ���� ��Ұ��� �ٲ���
        char temp = ary[i];              // �ٲٱ� �� ��Ұ� temp�� ����
        ary[i] = ary[length - i - 1];    // ���� 0,1,2 �ε����� ��Ұ� 5,4,3 �ε��� ��Ұ����� ��ȯ
        ary[length - i - 1] = temp;      // �ε��� 5,4,3�� ��Ұ��� ��ȯ �� 0,1,2 ��Ұ����� ��ȯ
        i++;
    }
    */
    i = 0;

    while (i < length / 2) { // �迭�� ���ݸ�ŭ �ݺ��Ͽ� ��Ҹ� ��ȯ
        if (i != length - i - 1) { // �迭�� �߾� �� ���� ��ҵ� ������ ��ҵ�� ��ȯ
            char temp = ary[i];
            ary[i] = ary[length - i - 1];
            ary[length - i - 1] = temp;
        }
        i++;
    }

    i = 0;
    cout << "�ٲ� �� �迭: ";
    while (i < length) {
        cout << ary[i]; // �迭 ��Ҹ� �ϳ��� ���
        i++;
    }
    cout << endl;

    return 0;
}
