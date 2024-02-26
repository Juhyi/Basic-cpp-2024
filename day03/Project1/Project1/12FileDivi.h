#pragma once
#ifndef HONG_CLASS_H
#define HONG_CLASS_H

#include <string>

class Hong {
public:
    Hong(const std::string& name, int age); // 생성자
    void ShowInfo(); // 정보 출력 메서드

private:
    std::string name;
    int age;
};

#endif
