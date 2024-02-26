#pragma once
#ifndef HONG_CLASS_H
#define HONG_CLASS_H

#include <string>

class Hong {
public:
    Hong(const char *name, int age, int year); // 생성자
    void ShowInfo(); // 정보 출력 메서드

private:
    char name;
    int age;
};

#endif
