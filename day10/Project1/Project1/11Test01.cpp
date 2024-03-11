#include <iostream>
#include <cstring>

class Grade {
private:
    char* name; // �л� �̸��� �����ϴ� ���ڿ� ������
    int kor;    // ���� ����
    int eng;    // ���� ����
    int math;   // ���� ����

public:
    
    Grade(const char* n, int k, int e, int m) : kor(k), eng(e), math(m) {
        // �̸��� ���� �޸� ���� �Ҵ�
        name = new char[strlen(n) + 1];
        // �־��� �̸��� �Ҵ�� �޸𸮿� ����
        strcpy(name, n);
    }

    // �Ҹ���: �������� �Ҵ�� �޸𸮸� ������
    ~Grade() {
        delete[] name;
    }

    // �л� �̸� ��ȯ
    const char* getName() const {
        return name;
    }

    // ���� ���
    int getTotal() const {
        return kor + eng + math;
    }

    // ��� ���
    float getAverage() const {
        return getTotal() / 3.0f;
    }

};

int main() {
    const int numStudents = 5;
    Grade student[numStudents];

    // �л� ���� �Է� �ޱ�
    for (int i = 0; i < numStudents; ++i) {
        char name[50];
        int kor, eng, math;
        std::cout << "�л� " << i + 1 << "�� �̸��� �Է��ϼ���: ";
        std::cin.getline(name, 50);
        std::cout << "���� ������ �Է��ϼ���: ";
        std::cin >> kor;
        std::cout << "���� ������ �Է��ϼ���: ";
        std::cin >> eng;
        std::cout << "���� ������ �Է��ϼ���: ";
        std::cin >> math;
 
        student[i] = &Grade(name, kor, eng, math);
    }

    // �л��� ������ ��� ���
    std::cout << "�л��� ������ ���:" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        std::cout << student[i].getName() << " - ����: " << student[i].getTotal() << ", ���: " << student[i].getAverage() << std::endl;
    }

    

    return 0;
}