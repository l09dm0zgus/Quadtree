#include "include/Rectangle.h"

Rectangle::Rectangle(const Point &position, const Point &size) :size(size)
{
    this->position = position;
}

Rectangle::Rectangle(float x, float y, float width, float height)
{
    position.setX(x);
    position.setY(y);
    size.setX(width);
    size.setY(height);
}

void Rectangle::setSize(const Point &size)
{
    this->size = size;
}

Point Rectangle::getSize()
{
    return size;
}

void Rectangle::setWidth(float width)
{
    size.setX(width);
}

float Rectangle::getWidth()
{
    return size.getX();
}

void Rectangle::setHeight(float height)
{
    size.setY(height);
}

float Rectangle::getHeight()
{
    return size.getY();
}
