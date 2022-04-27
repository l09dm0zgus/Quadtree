#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
   EXPORT_API Rectangle(const Point &position,const Point &size);
   EXPORT_API Rectangle(float x, float y,float width,float height);
   EXPORT_API void setSize(const Point &size);
   EXPORT_API Point getSize();
   EXPORT_API void setWidth(float width);
   EXPORT_API float getWidth();
   EXPORT_API void setHeight(float height);
   EXPORT_API float getHeight();
private:
    Point size;
};


