#include "12FileDivi.h"
#include <iostream>

Hong::Hong(const std::string& name, int age) : name(name), age(age) {}

void Hong::ShowInfo() {
    std::cout << "나는 " << age << " 백수 " << name << "!" << std::endl;
}


/*
* Class
* - 멤버변수와 멤버함수로 구성된다.
* - 클래스 내부에는 멤버들의 선언으로 작성된다.
* - 멤버함수의 정의를 외부로 빼낸다.(스코프연산자사용)
* - 일반적으로 멤버변수는 private, 멤버함수는 public를 사용한다.
* 
*/