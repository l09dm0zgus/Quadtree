#pragma once

#include "Point.h"
class Shape
{
public:
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
    void setPosition(const Point &position);
    Point getPosition();
protected:
    Point position;
};

