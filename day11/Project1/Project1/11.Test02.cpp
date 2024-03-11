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
        cout << "생성자 호출" << endl;;
       
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
    const int numStudents = 3;
    // Grade* gradeAry[3]  // 객체 포인터 배열
    Grade gradArry[numStudents];    // 객체 배열

    char name[50];
    int inkor, ineng, inmath;
    int num = 0;
    
    cout << "성적처리 학생 수" << endl;
    cin >> num;
    
    //vector<Grade> gradeAry(num);
    //vector<Grade*> gradeAry(num); // 프로그램 진행 중에 메모리를 동적 할당받음





    // 1. 하나의 입력을 받음 -> 3개 입력
    for (int i = 0; i < num; i++) {
        cout << "학생 이름: ";
        cin >> name;
        cout << "국어 점수를 입력하세요: ";
        cin >> inkor;
        cout << "영어 점수를 입력하세요: ";
        cin >> ineng;
        cout << "수학 점수를 입력하세요: ";
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

    
    
    cout << "국어 과목 총점: " << totalKor << ", 평균: " << totalKor/3 << endl;
    cout << "영어 과목 총점: " << totalEng << ", 평균: " << totalEng /3  << endl;
    cout << "수학 과목 총점: " << totalMath << ", 평균: " << totalMath /3  << endl;

    for (int i = 0; i < num; i++) {
        delete [i]gradArry;
    }

    return 0;
}

/*
5명의 이름과 국,영,수 3과목을 입력받아 학생별 총점과 평균, 그리고 과목별 총점과 평균을 구하시오.
1) 객체 포인터 배열 사용
2) 객체 배열 사용 -> 이걸로 하겠다!

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Grade
{
    char* name;         // 포인터를 사용하고 있다.
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
        printf("소멸자 호출\n");
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
    Grade gradeArr[3] = {};            // 객체 배열 생성 시 생성자 호출됨!

    char name[20];
    int inKor, inMat, inEng;

    // 1. 입력을 받는다.
    for (int i = 0; i < 3; i++) {
        cout << "이름 : ";
        cin >> name;

        cout << "국어점수 : ";
        cin >> inKor;

        cout << "영어점수 : ";
        cin >> inEng;

        cout << "수학점수 : ";
        cin >> inMat;
        cout << endl;

        //cout << name << inKor << inEng << inMat << endl;
        //2. 객체 생성 : 5개의 객체 생성, 객체 배열 or 객체  포인터 배열 중 뭘 쓸 것인가.. 이번엔 객체 배열을 쓰겠다
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
        //cout << "총점 : " << gradeArr[i]->sum() << endl << "평균 : " << gradeArr[i]->avr() << endl << endl;
        printf("%d번째 학생 총점 : %d,   평점 : %0.1f\n", i + 1, gradeArr[i].sum(), gradeArr[i].avr());
    }

    printf("\n");
    printf("국어 총점 : %d, 국어 평균 : %.1f\n", korSum, korSum / float(size(gradeArr)));
    printf("영어 총점 : %d, 영어 평균 : %.1f\n", EngSum, EngSum / float(size(gradeArr)));
    printf("수학 총점 : %d, 수학 평균 : %.1f\n\n", Matsum, Matsum / float(size(gradeArr)));

    for (int i = 0; i < 3; i++) {
        printf("객체 할당 소멸자 호출\n");
    }
    return 0;
}
*/