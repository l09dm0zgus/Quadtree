#pragma once

#include "Point.h"

class Circle
{
public:
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
    void setPosition(const Point &position);
    Point getPosition();
    void setRadius(float radius);
    float getRadius();
public:
    float radius;
    Point position;
};

