#pragma once
#include "Shape.h"

class IShapeCreator
{
public:
    virtual ~IShapeCreator();
    virtual Shape* create() = 0;
};
