#pragma once
#ifndef HONG_CLASS_H
#define HONG_CLASS_H

#include <string>

class Hong {
public:
    Hong(const std::string& name, int age); // ������
    void ShowInfo(); // ���� ��� �޼���

private:
    std::string name;
    int age;
};

#endif
