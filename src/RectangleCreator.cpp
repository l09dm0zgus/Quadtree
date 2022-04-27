#include "include/RectangleCreator.h"

Shape *RectangleCreator::create()
{
    return new Rectangle(0,0,0,0);
}
