#pragma once
#include "Object.h"
#include <ostream>

class Point
{
public:
	Point();
	Point(int x, int y, Object object);
	unsigned int distance(const Point &B);
	~Point();
	int getCoordX();
	int getCoordY();
	Object getType();
	void setType(Object obj);
	friend std::ostream& operator<<(std::ostream& os, const Point& p);
protected:
	int coordX;
	int coordY;
	Object type;
};
