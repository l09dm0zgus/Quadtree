#pragma once
#include "IShapeCreator.h"
#include "Circle.h"

class CircleCreator : public IShapeCreator
{
public:
    Shape *create() override;
};


