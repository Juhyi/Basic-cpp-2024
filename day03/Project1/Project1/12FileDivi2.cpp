#include "12FileDivi.h"
#include <iostream>

Hong::Hong(const std::string& name, int age) : name(name), age(age) {}

void Hong::ShowInfo() {
    std::cout << "���� " << age << " ��� " << name << "!" << std::endl;
}


/*
* Class
* - ��������� ����Լ��� �����ȴ�.
* - Ŭ���� ���ο��� ������� �������� �ۼ��ȴ�.
* - ����Լ��� ���Ǹ� �ܺη� ������.(�����������ڻ��)
* - �Ϲ������� ��������� private, ����Լ��� public�� ����Ѵ�.
* 
*/