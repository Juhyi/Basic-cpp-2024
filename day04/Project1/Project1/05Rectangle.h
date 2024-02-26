#pragma once
#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

# include "04Point.h"

class Rectangle
{
private:
	Point upLeft;
	Point lowRight;

public:
	bool InitMembers(const Point& u1, const Point & lr);
	void ShowRecInfo() const;
};

#endif