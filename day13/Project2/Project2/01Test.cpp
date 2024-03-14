#include <iostream>
using namespace std;

int main() {
    char ary[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int length = sizeof(ary) / sizeof(ary[0]); // 배열의 길이 계산 : 배열의 전체 크기를 자료형 크기로 나누면 => 배열의 길이

    int i = 0;

    cout << "바꾸기 전 배열: ";
    while (i < length) {
        cout << ary[i]; // 배열 요소를 하나씩 출력
        i++;
    }
    cout << endl;
    /*
    i = 0;
    while (i < length / 2) {             // 배열을 절반으로 나누어서 앞쪽 요소값을 뒤쪽 요소값과 바꿔줌
        char temp = ary[i];              // 바꾸기 전 요소값 temp에 저장
        ary[i] = ary[length - i - 1];    // 앞쪽 0,1,2 인덱스의 요소값 5,4,3 인덱스 요소값으로 변환
        ary[length - i - 1] = temp;      // 인덱스 5,4,3의 요소값에 변환 전 0,1,2 요소값으로 변환
        i++;
    }
    */
    i = 0;

    while (i < length / 2) { // 배열의 절반만큼 반복하여 요소를 교환
        if (i != length - i - 1) { // 배열의 중앙 전 왼쪽 요소들 오른쪽 요소들과 교환
            char temp = ary[i];
            ary[i] = ary[length - i - 1];
            ary[length - i - 1] = temp;
        }
        i++;
    }

    i = 0;
    cout << "바꾼 후 배열: ";
    while (i < length) {
        cout << ary[i]; // 배열 요소를 하나씩 출력
        i++;
    }
    cout << endl;

    return 0;
}
