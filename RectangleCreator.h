#pragma once
#include "IShapeCreator.h"
#include "Rectangle.h"

class RectangleCreator : public IShapeCreator
{
public:
    ~RectangleCreator(){};;
    Shape *create() override;
};

