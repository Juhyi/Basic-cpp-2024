#pragma once
#ifndef HONG_CLASS_H
#define HONG_CLASS_H

#include <string>

class Hong {
public:
    Hong(const char *name, int age, int year); // ������
    void ShowInfo(); // ���� ��� �޼���

private:
    char name;
    int age;
};

#endif
