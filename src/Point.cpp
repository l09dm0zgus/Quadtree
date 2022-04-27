#include "include/Point.h"

Point::Point(int x, int y):x(x),y(y)
{

}

void Point::setX(float x)
{
    this->x = x;
}

void Point::setY(float y)
{
    this->y = y;
}

float Point::getX()
{
    return x;
}

float Point::getY()
{
    return y;
}

