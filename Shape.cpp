#include "Shape.h"

void Shape::setPosition(const Point &position)
{
    this->position = position;
}

Point Shape::getPosition()
{
    return position;
}
