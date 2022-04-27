#pragma once
#include "Defines.h"

class Point
{
public:
   EXPORT_API Point(){};
   EXPORT_API Point(int x,int y);
   EXPORT_API void setX(float x);
   EXPORT_API void setY(float y);
   EXPORT_API float getX();
   EXPORT_API float getY();
private:
    float x;
    float y;
};

