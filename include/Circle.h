#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
   EXPORT_API void setRadius(float radius);
   EXPORT_API float getRadius();

private:
    float radius;
};

