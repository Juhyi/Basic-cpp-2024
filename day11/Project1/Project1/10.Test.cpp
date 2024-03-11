#include <iostream>
#include <cstring>
using namespace std;
// 
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

    ~Grade() {
        cout << "객체 " << name << " 소멸자 호출" << endl;
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
    Grade* gradAry[3];

    char name[50];
    int inkor, ineng, inmath;

    for (int i = 0; i < 3; i++) {
        cout << "학생 이름: ";
        cin >> name;
        cout << "국어 점수를 입력하세요: ";
        cin >> inkor;
        cout << "영어 점수를 입력하세요: ";
        cin >> ineng;
        cout << "수학 점수를 입력하세요: ";
        cin >> inmath;

        gradAry[i] = new Grade(name, inkor, ineng, inmath);
    }

    int totalKor = 0;
    int totalEng = 0;
    int totalMath = 0;

    for (int i = 0; i < 3; i++) {
        totalKor += gradAry[i]->getKor();
        totalEng += gradAry[i]->getEng();
        totalMath += gradAry[i]->getMath();
    }

    float avgKor = 0;
    float avgEng = 0;
    float avgMath = 0;

    for (int i = 0; i < 3; i++) {
        avgKor = totalKor / 3.0f;
        avgEng = totalEng / 3.0f;
        avgMath = totalMath / 3.0f;
    }

    cout << "국어 과목 총점: " << totalKor << "국어 과목 평균"<< avgKor <<endl;
    cout << "영어 과목 총점: " << totalEng << "영어 과목 평균" << avgEng <<  endl;
    cout << "수학 과목 총점: " << totalMath <<"수학 과목 평균" << avgMath <<endl;

    for (int i = 0; i < 3; i++) {
        delete gradAry[i];
    }

    return 0;
}