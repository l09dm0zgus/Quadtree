#pragma once
#include "Point.h"

class Rectangle
{
public:
    Rectangle(const Point &position,const Point &size);
    Rectangle(float x, float y,float width,float height);
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
    void setPosition(const Point &position);
    Point getPosition();
    void  setSize(const Point &size);
    Point getSize();
    void setWidth(float width);
    float getWidth();
    void setHeight(float height);
    float getHeight();
private:
    Point size;
    Point position;

};


