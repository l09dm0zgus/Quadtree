#include "Circle.h"



float Circle::getX()
{
    return position.getX();
}

float Circle::getY()
{
    return position.getY();
}

float Circle::getRadius()
{
    return radius;
}

Point Circle::getPosition()
{
    return position;
}

void Circle::setX(float x)
{
    position.setX(x);
}

void Circle::setY(float y)
{
    position.setY(y);
}

void Circle::setPosition(const Point &position)
{
    this->position = position;
}

void Circle::setRadius(float radius)
{
    this->radius = radius;
}
