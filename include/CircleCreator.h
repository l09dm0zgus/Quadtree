#pragma once
#include "IShapeCreator.h"
#include "Circle.h"

class CircleCreator : public IShapeCreator
{
public:
   EXPORT_API Shape *create() override;
};


