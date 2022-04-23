#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(const Point &position,const Point &size);
    Rectangle(float x, float y,float width,float height);
    void  setSize(const Point &size);
    Point getSize();
    void setWidth(float width);
    float getWidth();
    void setHeight(float height);
    float getHeight();
private:
    Point size;
};


