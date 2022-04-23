#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
    void setRadius(float radius);
    float getRadius();
public:
    float radius;
};

