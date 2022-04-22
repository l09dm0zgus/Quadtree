#include "Circle.h"

float Circle::getX()
{
    return position.getX();
}

float Circle::getY()
{
    return position.getY();
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

Point Circle::getPosition()
{
    return position;
}

void Circle::setRadius(float radius)
{
    this->radius = radius;
}

float Circle::getRadius()
{
    return radius;
}
