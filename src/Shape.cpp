#include "include/Shape.h"

float Shape::getX()
{
    return position.getX();
}

float Shape::getY()
{
    return position.getY();
}

void Shape::setX(float x)
{
    position.setX(x);
}

void Shape::setY(float y)
{
    position.setY(y);
}

void Shape::setPosition(const Point &position)
{
    this->position = position;
}

Point Shape::getPosition()
{
    return position;
}

