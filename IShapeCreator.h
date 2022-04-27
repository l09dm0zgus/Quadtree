#pragma once
#include "Shape.h"

class IShapeCreator
{
public:
   EXPORT_API virtual ~IShapeCreator(){};
   EXPORT_API virtual Shape* create() = 0;
};
