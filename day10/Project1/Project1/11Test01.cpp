#include <iostream>
#include <cstring>

class Grade {
private:
    char* name; // 학생 이름을 저장하는 문자열 포인터
    int kor;    // 국어 성적
    int eng;    // 영어 성적
    int math;   // 수학 성적

public:
    
    Grade(const char* n, int k, int e, int m) : kor(k), eng(e), math(m) {
        // 이름을 위한 메모리 동적 할당
        name = new char[strlen(n) + 1];
        // 주어진 이름을 할당된 메모리에 복사
        strcpy(name, n);
    }

    // 소멸자: 동적으로 할당된 메모리를 해제함
    ~Grade() {
        delete[] name;
    }

    // 학생 이름 반환
    const char* getName() const {
        return name;
    }

    // 총점 계산
    int getTotal() const {
        return kor + eng + math;
    }

    // 평균 계산
    float getAverage() const {
        return getTotal() / 3.0f;
    }

};

int main() {
    const int numStudents = 5;
    Grade student[numStudents];

    // 학생 정보 입력 받기
    for (int i = 0; i < numStudents; ++i) {
        char name[50];
        int kor, eng, math;
        std::cout << "학생 " << i + 1 << "의 이름을 입력하세요: ";
        std::cin.getline(name, 50);
        std::cout << "국어 점수를 입력하세요: ";
        std::cin >> kor;
        std::cout << "영어 점수를 입력하세요: ";
        std::cin >> eng;
        std::cout << "수학 점수를 입력하세요: ";
        std::cin >> math;
 
        student[i] = &Grade(name, kor, eng, math);
    }

    // 학생별 총점과 평균 출력
    std::cout << "학생별 총점과 평균:" << std::endl;
    for (int i = 0; i < numStudents; ++i) {
        std::cout << student[i].getName() << " - 총점: " << student[i].getTotal() << ", 평균: " << student[i].getAverage() << std::endl;
    }

    

    return 0;
}