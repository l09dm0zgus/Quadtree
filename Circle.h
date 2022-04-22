#pragma once

#include "Point.h"

class Circle
{
public:
    float getX();
    float getY();
    float getRadius();
    Point getPosition();
    void setX(float x);
    void setY(float y);
    void setPosition(const Point &position);
    void setRadius(float radius);
public:
    float radius;
    Point position;
};

