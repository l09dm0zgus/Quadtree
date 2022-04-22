#include "Rectangle.h"

Rectangle::Rectangle(const Point &position, const Point &size) :size(size),position(position)
{

}

Rectangle::Rectangle(float x, float y, float width, float height)
{
    position.setX(x);
    position.setY(y);
    size.setX(width);
    size.setY(height);
}

float Rectangle::getX()
{
    return position.getX();
}

float Rectangle::getY()
{
    return position.getY();
}

void Rectangle::setX(float x)
{
    position.setX(x);
}

void Rectangle::setY(float y)
{
    position.setY(y);
}

void Rectangle::setPosition(const Point &position)
{
    this->position = position;
}

Point Rectangle::getPosition()
{
    return position;
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
