#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Grade {
private:
    char* name;
    int kor;
    int eng;
    int math;

public:
    Grade(const char* n, int k, int e, int m) {
        this->kor = k;
        this->eng = e;
        this->math = m;

        this->name = new char[strlen(n) + 1];
        strcpy(this->name, n);
    }
    Grade()
    {
        cout << "������ ȣ��" << endl;;
       
    }
   
    ~Grade() {
        cout << "��ü " << name << " �Ҹ��� ȣ��" << endl;
        delete[] name;
    }

    const char* getName() const {
        return name;
    }

    int getKor() const {
        return kor;
    }

    int getEng() const {
        return eng;
    }

    int getMath() const {
        return math;
    }

    int getTotal() const {
        return kor + eng + math;
    }

    float getAverage() const {
        return getTotal() / 3.0f;
    }
};

int main() {
    const int numStudents = 3;
    // Grade* gradeAry[3]  // ��ü ������ �迭
    Grade gradArry[numStudents];    // ��ü �迭

    char name[50];
    int inkor, ineng, inmath;
    int num = 0;
    
    cout << "����ó�� �л� ��" << endl;
    cin >> num;
    
    //vector<Grade> gradeAry(num);
    //vector<Grade*> gradeAry(num); // ���α׷� ���� �߿� �޸𸮸� ���� �Ҵ����





    // 1. �ϳ��� �Է��� ���� -> 3�� �Է�
    for (int i = 0; i < num; i++) {
        cout << "�л� �̸�: ";
        cin >> name;
        cout << "���� ������ �Է��ϼ���: ";
        cin >> inkor;
        cout << "���� ������ �Է��ϼ���: ";
        cin >> ineng;
        cout << "���� ������ �Է��ϼ���: ";
        cin >> inmath;

        gradArry(num) = Grade(name, inkor, ineng, inmath);
    }

    int totalKor = 0;
    int totalEng = 0;
    int totalMath = 0;

    

    for (int i = 0; i < num; i++) {
        totalKor += gradArry[i].getKor();
        totalEng += gradArry[i].getEng();
        totalMath += gradArry[i].getMath();
    }

    
    
    cout << "���� ���� ����: " << totalKor << ", ���: " << totalKor/3 << endl;
    cout << "���� ���� ����: " << totalEng << ", ���: " << totalEng /3  << endl;
    cout << "���� ���� ����: " << totalMath << ", ���: " << totalMath /3  << endl;

    for (int i = 0; i < num; i++) {
        delete [i]gradArry;
    }

    return 0;
}

/*
5���� �̸��� ��,��,�� 3������ �Է¹޾� �л��� ������ ���, �׸��� ���� ������ ����� ���Ͻÿ�.
1) ��ü ������ �迭 ���
2) ��ü �迭 ��� -> �̰ɷ� �ϰڴ�!

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Grade
{
    char* name;         // �����͸� ����ϰ� �ִ�.
    int kor;
    int mat;
    int eng;

public:
    Grade() {
        name = NULL;
        kor = 0;
        mat = 0;
        eng = 0;
    }
    Grade(const char* myname, int mykor, int myeng, int mymat)
    {
        name = new char[strlen(myname) + 1];
        strcpy(this->name, myname);
        kor = mykor;
        eng = myeng;
        mat = mymat;
    }
    void AddStudent(char* myname, int mykor, int myeng, int mymat)
    {
        name = myname;
        kor = mykor;
        eng = myeng;
        mat = mymat;
    }
    ~Grade()
    {
        printf("�Ҹ��� ȣ��\n");
    }
    int getKor()
    {
        return kor;
    }
    int getMat()
    {
        return mat;
    }
    int getEng()
    {
        return eng;
    }
    int sum() const
    {
        int sum = kor + eng + mat;
        return sum;
    }
    double avr() const
    {
        double avr = sum() / 3.0;
        return avr;
    }
};

int main(void)
{
    Grade gradeArr[3] = {};            // ��ü �迭 ���� �� ������ ȣ���!

    char name[20];
    int inKor, inMat, inEng;

    // 1. �Է��� �޴´�.
    for (int i = 0; i < 3; i++) {
        cout << "�̸� : ";
        cin >> name;

        cout << "�������� : ";
        cin >> inKor;

        cout << "�������� : ";
        cin >> inEng;

        cout << "�������� : ";
        cin >> inMat;
        cout << endl;

        //cout << name << inKor << inEng << inMat << endl;
        //2. ��ü ���� : 5���� ��ü ����, ��ü �迭 or ��ü  ������ �迭 �� �� �� ���ΰ�.. �̹��� ��ü �迭�� ���ڴ�
        gradeArr[i].AddStudent(name, inKor, inEng, inMat);
    }

    int korSum = 0;
    int EngSum = 0;
    int Matsum = 0;
    for (int i = 0; i < 3; i++) {
        korSum += gradeArr[i].getKor();
        EngSum += gradeArr[i].getEng();
        Matsum += gradeArr[i].getMat();
    }

    for (int i = 0; i < 3; i++)
    {
        //cout << "���� : " << gradeArr[i]->sum() << endl << "��� : " << gradeArr[i]->avr() << endl << endl;
        printf("%d��° �л� ���� : %d,   ���� : %0.1f\n", i + 1, gradeArr[i].sum(), gradeArr[i].avr());
    }

    printf("\n");
    printf("���� ���� : %d, ���� ��� : %.1f\n", korSum, korSum / float(size(gradeArr)));
    printf("���� ���� : %d, ���� ��� : %.1f\n", EngSum, EngSum / float(size(gradeArr)));
    printf("���� ���� : %d, ���� ��� : %.1f\n\n", Matsum, Matsum / float(size(gradeArr)));

    for (int i = 0; i < 3; i++) {
        printf("��ü �Ҵ� �Ҹ��� ȣ��\n");
    }
    return 0;
}
*/