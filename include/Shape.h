#pragma once

#include "Point.h"
#include "Defines.h"
class Shape
{
public:
   EXPORT_API float getX();
   EXPORT_API float getY();
   EXPORT_API void setX(float x);
   EXPORT_API void setY(float y);
   EXPORT_API void setPosition(const Point &position);
   EXPORT_API Point getPosition();
protected:
    Point position;
};


