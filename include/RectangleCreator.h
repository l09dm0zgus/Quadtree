#pragma once
#include "IShapeCreator.h"
#include "Rectangle.h"

class RectangleCreator : public IShapeCreator
{
public:
   EXPORT_API Shape *create() override;
};

